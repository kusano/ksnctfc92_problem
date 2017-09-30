#!/bin/bash

# システム全体を書き換えるので、まっさらな環境以外では実行しないでください
# CentOS 7 x86_64 minimal向け

set -e

cat <<EOF > /etc/selinux/config
SELINUX=disabled
EOF
setenforce 0

yum -y update

cd

yum -y install git
git clone --depth 1 https://github.com/kusano/ksnctfc92_problem.git

# md5
useradd md5

cp -r ksnctfc92_problem/server/md5 /home/
chown -R root:md5 /home/md5
chmod 750 /home/md5
chmod 750 /home/md5/md5
chmod 750 /home/md5/md5.sh
chmod 640 /home/md5/flag.txt
chmod 640 /home/md5/flag2.txt

yum -y install xinetd
cp ksnctfc92_problem/server/md5-stream /etc/xinetd.d/
chmod 600 /etc/xinetd.d/md5-stream
systemctl enable xinetd

firewall-cmd --add-port 55555/tcp --permanent

yum -y install httpd
systemctl enable httpd
firewall-cmd --add-port 80/tcp --permanent
ln -s /lib64/libc.so.6 /var/www/html/libc.so.6

# kaisendon
useradd kaisendon

yum -y install unzip
unzip ksnctfc92_problem/problems/W/kaisendon.zip -d /home/kaisendon/
cp ksnctfc92_problem/W/config.js /home/kaisendon/kaisendon/
chown -R kaisendon:kaisendon /home/kaisendon
chmod -R 700 /home/kaisendon

yum -y install epel-release
yum -y install npm --enablerepo=epel
npm install -g forever

cd /home/kaisendon/kaisendon
sudo -u kaisendon npm install
cd -

cat <<EOF | sudo -u kaisendon crontab
@reboot NODE_ENV=production FLAG1=FLAG{3snoa6p4wncj1hpf} FLAG2=FLAG{vakdriti4zzlj55p} FLAG3=FLAG{bpodf2es4k9e42rf} forever start /home/kaisendon/kaisendon/bin/www
EOF

firewall-cmd --add-port 3000/tcp --permanent

# restrict
chmod u-s /usr/bin/*
chmod g-s /usr/bin/*
chmod u+s /usr/bin/sudo
chmod u+s /usr/bin/su
chmod u+s /usr/bin/crontab

firewall-cmd --direct --permanent --add-rule ipv4 filter OUTPUT 0 -m state --state RELATED,ESTABLISHED -j ACCEPT
firewall-cmd --direct --permanent --add-rule ipv4 filter OUTPUT 999 -m owner --uid-owner kaisendon -j REJECT
firewall-cmd --direct --permanent --add-rule ipv4 filter OUTPUT 999 -m owner --uid-owner md5 -j REJECT
firewall-cmd --direct --permanent --add-rule ipv6 filter OUTPUT 0 -m state --state RELATED,ESTABLISHED -j ACCEPT
firewall-cmd --direct --permanent --add-rule ipv6 filter OUTPUT 999 -m owner --uid-owner kaisendon -j REJECT
firewall-cmd --direct --permanent --add-rule ipv6 filter OUTPUT 999 -m owner --uid-owner md5 -j REJECT

# reboot
rm -rf ksnctfc92_problem
reboot
