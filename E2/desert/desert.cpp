#include <Windows.h>
#include <tchar.h>
#include <gdiplus.h>
#include <vector>

#pragma comment(lib, "Gdiplus.lib")

using namespace Gdiplus;
using namespace std;

const uint64_t W = 12;
const uint64_t H = 9;
const uint64_t PS = 32;

uint64_t currentX = 0x8000000000000000ULL;
uint64_t currentY = 0x8000000000000000ULL;
//  flag1
//uint64_t currentX = 16819585654921967928ULL;
//uint64_t currentY = 9709471222094771744ULL;
//  flag2
//uint64_t currentX = 7088916131484792129ULL;
//uint64_t currentY = 3638475783989113732ULL;
const uint64_t MAX_NODE = 10000;
const uint64_t invalid = 0xffffffffffffffffULL;
uint64_t node[MAX_NODE][4] =
{
{310, invalid, invalid, 1},
{invalid, 2, invalid, invalid},
{invalid, 3, invalid, invalid},
{4, invalid, invalid, invalid},
{invalid, 5, invalid, invalid},
{invalid, invalid, 6, invalid},
{invalid, invalid, 7, invalid},
{invalid, 8, invalid, invalid},
{invalid, invalid, 9, invalid},
{invalid, 10, invalid, invalid},
{invalid, invalid, invalid, 11},
{invalid, invalid, 12, invalid},
{invalid, invalid, invalid, 13},
{invalid, invalid, 14, invalid},
{invalid, invalid, invalid, 15},
{invalid, 16, invalid, invalid},
{invalid, invalid, 17, invalid},
{invalid, invalid, 18, invalid},
{invalid, invalid, invalid, 19},
{invalid, invalid, 20, invalid},
{invalid, invalid, invalid, 21},
{invalid, 22, invalid, invalid},
{23, invalid, invalid, invalid},
{24, invalid, invalid, invalid},
{invalid, invalid, 25, invalid},
{26, invalid, invalid, invalid},
{invalid, invalid, 27, invalid},
{28, invalid, invalid, invalid},
{invalid, 29, invalid, invalid},
{30, invalid, invalid, invalid},
{invalid, invalid, invalid, 31},
{32, invalid, invalid, invalid},
{33, invalid, invalid, invalid},
{34, invalid, invalid, invalid},
{invalid, invalid, 35, invalid},
{36, invalid, invalid, invalid},
{invalid, invalid, 37, invalid},
{invalid, invalid, invalid, 38},
{invalid, 39, invalid, invalid},
{invalid, invalid, 40, invalid},
{invalid, invalid, invalid, 41},
{invalid, invalid, invalid, 42},
{invalid, 43, invalid, invalid},
{invalid, invalid, 44, invalid},
{45, invalid, invalid, invalid},
{invalid, invalid, 46, invalid},
{invalid, invalid, 47, invalid},
{invalid, 48, invalid, invalid},
{49, invalid, invalid, invalid},
{50, invalid, invalid, invalid},
{invalid, invalid, invalid, 51},
{invalid, invalid, invalid, 52},
{invalid, 53, invalid, invalid},
{invalid, invalid, 54, invalid},
{invalid, invalid, 55, invalid},
{invalid, 56, invalid, invalid},
{57, 219, invalid, invalid},
{58, 76, invalid, invalid},
{invalid, invalid, invalid, 59},
{invalid, 60, invalid, invalid},
{invalid, 61, invalid, invalid},
{62, 65, 70, 73},
{63, 64, 67, 68},
{3, 3, 3, 0},
{3, 3, 0, 0},
{66, 75, 69, 82},
{0, 3, 0, 3},
{3, 3, 3, 0},
{3, 0, 0, 0},
{0, 3, 0, 3},
{71, 72, invalid, invalid},
{3, 0, invalid, invalid},
{0, 0, invalid, invalid},
{74, 84, invalid, invalid},
{0, 3, invalid, invalid},
{0, 0, 0, 0},
{invalid, invalid, 77, 150},
{78, 110, invalid, invalid},
{79, 98, invalid, invalid},
{80, 88, 85, 95},
{81, 87, 83, 91},
{0, 0, 0, 0},
{0, 0, 0, 0},
{0, 0, 0, 0},
{3, 3, invalid, invalid},
{86, 94, invalid, invalid},
{3, 0, invalid, invalid},
{3, 3, 3, 0},
{89, 90, 92, 93},
{3, 3, 0, 3},
{0, 3, 0, 3},
{3, 3, 3, 0},
{3, 3, 0, 3},
{0, 3, 0, 3},
{3, 0, invalid, invalid},
{96, 97, invalid, invalid},
{0, 3, invalid, invalid},
{0, 3, invalid, invalid},
{99, 107, 104, 117},
{100, 101, 102, 103},
{3, 3, 0, 0},
{3, 0, 0, 0},
{0, 3, 0, 0},
{3, 0, 3, 0},
{105, 106, invalid, invalid},
{3, 3, invalid, invalid},
{3, 0, invalid, invalid},
{108, 109, 114, 115},
{0, 3, 0, 3},
{3, 0, 0, 0},
{111, 131, invalid, invalid},
{112, 123, 120, 128},
{113, 122, 116, 125},
{0, 3, 0, 3},
{3, 3, 0, 3},
{0, 0, 0, 0},
{0, 3, 0, 0},
{118, 119, invalid, invalid},
{0, 3, invalid, invalid},
{3, 0, invalid, invalid},
{121, 127, invalid, invalid},
{0, 3, invalid, invalid},
{3, 3, 0, 0},
{124, 130, 126, 135},
{3, 0, 3, 0},
{3, 3, 0, 0},
{3, 0, 3, 0},
{3, 3, invalid, invalid},
{129, 138, invalid, invalid},
{3, 0, invalid, invalid},
{3, 3, 3, 0},
{132, 142, 139, 147},
{133, 134, 136, 137},
{3, 3, 0, 3},
{0, 3, 0, 0},
{3, 0, 0, 0},
{0, 3, 0, 3},
{0, 3, 0, 3},
{0, 0, invalid, invalid},
{140, 141, invalid, invalid},
{0, 3, invalid, invalid},
{0, 3, invalid, invalid},
{143, 144, 145, 146},
{3, 3, 0, 0},
{3, 0, 3, 0},
{3, 3, 0, 0},
{3, 0, 0, 0},
{148, 149, invalid, invalid},
{3, 3, invalid, invalid},
{3, 0, invalid, invalid},
{151, 186, invalid, invalid},
{152, 167, invalid, invalid},
{153, 156, 161, 164},
{154, 155, 158, 159},
{3, 3, 3, 0},
{3, 3, 0, 3},
{157, 166, 160, 170},
{0, 3, 0, 3},
{3, 3, 0, 0},
{3, 3, 0, 3},
{0, 3, 0, 0},
{162, 163, invalid, invalid},
{3, 3, invalid, invalid},
{3, 3, invalid, invalid},
{165, 172, invalid, invalid},
{0, 3, invalid, invalid},
{3, 3, 0, 0},
{168, 176, 173, 183},
{169, 175, 171, 179},
{3, 0, 0, 0},
{3, 3, 0, 0},
{3, 0, 3, 0},
{3, 3, invalid, invalid},
{174, 182, invalid, invalid},
{3, 0, invalid, invalid},
{0, 0, 0, 0},
{177, 178, 180, 181},
{0, 3, 0, 3},
{0, 3, 0, 0},
{0, 0, 0, 0},
{0, 3, 0, 3},
{0, 3, 0, 3},
{0, 0, invalid, invalid},
{184, 185, invalid, invalid},
{0, 3, invalid, invalid},
{0, 3, invalid, invalid},
{187, 199, invalid, invalid},
{188, 196, 193, 205},
{189, 190, 191, 192},
{3, 3, 0, 0},
{3, 0, 3, 0},
{3, 3, 0, 0},
{3, 0, 0, 0},
{194, 195, invalid, invalid},
{3, 3, invalid, invalid},
{3, 0, invalid, invalid},
{197, 198, 202, 203},
{3, 3, 0, 0},
{3, 3, 0, 3},
{200, 211, 208, 216},
{201, 210, 204, 213},
{0, 0, 0, 0},
{3, 3, 3, 0},
{3, 3, 0, 0},
{0, 0, 0, 0},
{206, 207, invalid, invalid},
{3, 3, invalid, invalid},
{3, 3, invalid, invalid},
{209, 215, invalid, invalid},
{0, 0, invalid, invalid},
{0, 0, 0, 0},
{212, 218, 214, 227},
{3, 0, 3, 0},
{0, 0, 0, 0},
{3, 0, 3, 0},
{0, 0, invalid, invalid},
{217, 230, invalid, invalid},
{3, 0, invalid, invalid},
{3, 3, 3, 0},
{220, invalid, invalid, invalid},
{invalid, invalid, 221, 289},
{222, 257, invalid, invalid},
{223, 242, invalid, invalid},
{224, 234, 231, 239},
{225, 226, 228, 229},
{3, 3, 0, 0},
{0, 3, 0, 3},
{3, 3, 3, 0},
{3, 3, 0, 3},
{0, 3, 0, 0},
{3, 3, invalid, invalid},
{232, 233, invalid, invalid},
{3, 3, invalid, invalid},
{0, 0, invalid, invalid},
{235, 236, 237, 238},
{3, 3, 0, 0},
{3, 0, 3, 0},
{0, 0, 0, 0},
{3, 0, 3, 0},
{240, 241, invalid, invalid},
{0, 0, invalid, invalid},
{3, 0, invalid, invalid},
{243, 246, 251, 254},
{244, 245, 248, 249},
{3, 3, 0, 0},
{3, 3, 0, 3},
{247, 256, 250, 261},
{0, 3, 0, 3},
{3, 3, 3, 0},
{3, 3, 0, 0},
{0, 3, 0, 0},
{252, 253, invalid, invalid},
{3, 3, invalid, invalid},
{3, 3, invalid, invalid},
{255, 263, invalid, invalid},
{0, 0, invalid, invalid},
{3, 3, 0, 0},
{258, 277, invalid, invalid},
{259, 267, 264, 274},
{260, 266, 262, 270},
{3, 0, 3, 0},
{0, 0, 0, 0},
{3, 0, 3, 0},
{0, 0, invalid, invalid},
{265, 273, invalid, invalid},
{3, 0, invalid, invalid},
{3, 3, 3, 0},
{268, 269, 271, 272},
{3, 3, 0, 3},
{0, 3, 0, 3},
{3, 0, 3, 0},
{0, 3, 0, 3},
{0, 3, 0, 3},
{3, 3, invalid, invalid},
{275, 276, invalid, invalid},
{3, 3, invalid, invalid},
{0, 3, invalid, invalid},
{278, 286, 283, 297},
{279, 280, 281, 282},
{3, 3, 0, 0},
{3, 0, 3, 0},
{3, 3, 0, 0},
{3, 0, 3, 0},
{284, 285, invalid, invalid},
{3, 3, invalid, invalid},
{3, 0, invalid, invalid},
{287, 288, 294, 295},
{3, 3, 3, 0},
{3, 3, 0, 3},
{290, invalid, invalid, invalid},
{291, invalid, invalid, invalid},
{292, 303, 300, 308},
{293, 302, 296, 305},
{0, 0, 0, 0},
{3, 0, 0, 0},
{0, 3, 0, 3},
{0, 0, 0, 0},
{298, 299, invalid, invalid},
{0, 0, invalid, invalid},
{0, 3, invalid, invalid},
{301, 307, invalid, invalid},
{0, 0, invalid, invalid},
{3, 3, 0, 3},
{304, invalid, 306, invalid},
{0, 0, 0, 0},
{0, 3, 0, 3},
{3, 0, 0, 0},
{3, 3, invalid, invalid},
{309, invalid, invalid, invalid},
{0, 0, invalid, invalid},
{invalid, 311, invalid, invalid},
{invalid, invalid, invalid, 312},
{invalid, invalid, 313, invalid},
{314, invalid, invalid, invalid},
{315, invalid, invalid, invalid},
{invalid, invalid, invalid, 316},
{317, invalid, invalid, invalid},
{318, invalid, invalid, invalid},
{invalid, invalid, invalid, 319},
{invalid, invalid, invalid, 320},
{invalid, invalid, 321, invalid},
{invalid, invalid, 322, invalid},
{invalid, invalid, 323, invalid},
{invalid, invalid, 324, invalid},
{325, invalid, invalid, invalid},
{invalid, 326, invalid, invalid},
{invalid, invalid, invalid, 327},
{invalid, invalid, invalid, 328},
{invalid, invalid, 329, invalid},
{330, invalid, invalid, invalid},
{invalid, invalid, 331, invalid},
{invalid, invalid, invalid, 332},
{invalid, 333, invalid, invalid},
{invalid, 334, invalid, invalid},
{invalid, invalid, 335, invalid},
{invalid, invalid, invalid, 336},
{invalid, invalid, 337, invalid},
{invalid, 338, invalid, invalid},
{339, invalid, invalid, invalid},
{invalid, invalid, 340, invalid},
{invalid, 341, invalid, invalid},
{invalid, invalid, invalid, 342},
{343, invalid, invalid, invalid},
{invalid, invalid, invalid, 344},
{invalid, invalid, invalid, 345},
{346, invalid, invalid, invalid},
{invalid, invalid, 347, invalid},
{invalid, 348, invalid, invalid},
{invalid, 349, invalid, invalid},
{invalid, invalid, invalid, 350},
{351, invalid, invalid, invalid},
{invalid, 352, invalid, invalid},
{353, invalid, invalid, invalid},
{invalid, invalid, invalid, 354},
{invalid, 355, invalid, invalid},
{invalid, 356, invalid, invalid},
{invalid, 357, invalid, invalid},
{invalid, 358, invalid, invalid},
{invalid, 359, invalid, invalid},
{invalid, invalid, invalid, 360},
{invalid, invalid, invalid, 361},
{362, invalid, invalid, invalid},
{invalid, 363, invalid, invalid},
{invalid, invalid, 364, invalid},
{invalid, invalid, invalid, 365},
{invalid, invalid, 366, 516},
{invalid, 367, invalid, invalid},
{368, 443, invalid, invalid},
{369, 406, invalid, invalid},
{370, 386, 379, 394},
{invalid, invalid, 371, 374},
{372, 373, 376, 377},
{invalid, 6, invalid, 6},
{6, 6, 0, 0},
{375, 385, 378, 390},
{6, 0, 0, 0},
{invalid, 6, invalid, 6},
{6, 6, 0, 0},
{0, 0, 0, 0},
{380, 383, invalid, invalid},
{381, 382, invalid, invalid},
{invalid, 6, invalid, invalid},
{0, 0, invalid, invalid},
{384, 393, invalid, invalid},
{0, 0, invalid, invalid},
{6, 0, 6, 0},
{invalid, invalid, 387, 398},
{388, 389, 391, 392},
{0, 0, 0, 0},
{0, 6, 0, 6},
{6, 0, 6, 0},
{0, 0, 0, 0},
{0, 6, 0, 6},
{6, 6, invalid, invalid},
{395, 403, invalid, invalid},
{396, 397, invalid, invalid},
{6, 6, invalid, invalid},
{0, 6, invalid, invalid},
{399, 400, 401, 402},
{6, 6, 0, 0},
{6, 0, 6, 0},
{6, 6, 0, 0},
{6, 0, 6, 0},
{404, 405, invalid, invalid},
{0, 0, invalid, invalid},
{6, 0, invalid, invalid},
{407, 423, 416, 429},
{invalid, invalid, 408, 411},
{409, 410, 413, 414},
{6, 6, 6, 0},
{6, 6, 0, 0},
{412, 422, 415, 426},
{0, 0, 0, 0},
{6, 0, 6, 0},
{6, 6, 0, 6},
{0, 6, 0, 0},
{417, 420, invalid, invalid},
{418, 419, invalid, invalid},
{6, 6, invalid, invalid},
{6, 6, invalid, invalid},
{421, 428, invalid, invalid},
{0, 0, invalid, invalid},
{6, 6, 6, 0},
{invalid, invalid, 424, 433},
{425, 432, 427, 436},
{0, 0, 0, 0},
{6, 0, 6, 0},
{0, 0, 0, 0},
{6, 6, invalid, invalid},
{430, 440, invalid, invalid},
{431, 439, invalid, invalid},
{0, 0, invalid, invalid},
{6, 6, 6, 0},
{434, 435, 437, 438},
{6, 6, 0, 6},
{0, 6, 0, 6},
{6, 6, 6, 0},
{6, 6, 0, 6},
{0, 6, 0, 0},
{6, 6, invalid, invalid},
{441, 442, invalid, invalid},
{6, 6, invalid, invalid},
{0, 0, invalid, invalid},
{444, 479, invalid, invalid},
{445, 458, 451, 467},
{invalid, invalid, 446, 455},
{447, 448, 449, 450},
{6, 6, 0, 0},
{6, 0, 6, 0},
{0, 0, 0, 0},
{6, 0, 6, 0},
{452, 464, invalid, invalid},
{453, 454, invalid, invalid},
{0, 0, invalid, invalid},
{6, 0, invalid, invalid},
{456, 457, 461, 462},
{6, 6, 6, 0},
{6, 6, 0, 6},
{invalid, invalid, 459, 471},
{460, 470, 463, 473},
{0, 6, 0, 0},
{6, 0, 6, 0},
{0, 6, 0, 6},
{0, 6, 0, 0},
{465, 466, invalid, invalid},
{6, 6, invalid, invalid},
{6, 6, invalid, invalid},
{468, 476, invalid, invalid},
{469, 475, invalid, invalid},
{0, 6, invalid, invalid},
{6, 6, 0, 0},
{472, 478, 474, 484},
{6, 0, 6, 0},
{6, 6, 0, 0},
{6, 0, 6, 0},
{6, 6, invalid, invalid},
{477, 487, invalid, invalid},
{6, 0, invalid, invalid},
{6, 6, 0, 0},
{480, 500, 488, 509},
{invalid, invalid, 481, 492},
{482, 483, 485, 486},
{6, 6, 0, 6},
{0, 0, 0, 0},
{6, 6, 6, 0},
{6, 6, 0, 0},
{0, 0, 0, 0},
{6, 6, invalid, invalid},
{489, 497, invalid, invalid},
{490, 491, invalid, invalid},
{6, 6, invalid, invalid},
{0, 0, invalid, invalid},
{493, 494, 495, 496},
{0, 0, 0, 0},
{6, 0, 6, 0},
{0, 0, 0, 0},
{6, 0, 6, 0},
{498, 499, invalid, invalid},
{0, 0, invalid, invalid},
{6, 0, invalid, invalid},
{invalid, invalid, 501, 504},
{502, 503, 506, 507},
{6, 6, 6, 0},
{6, 6, 0, 6},
{505, 515, 508, 523},
{0, 6, 0, 6},
{6, 6, 0, 0},
{6, 6, 0, 6},
{0, 6, 0, 6},
{510, 513, invalid, invalid},
{511, 512, invalid, invalid},
{6, 6, invalid, invalid},
{6, 6, invalid, invalid},
{514, 525, invalid, invalid},
{0, 6, invalid, invalid},
{6, 6, 0, 0},
{517, invalid, invalid, invalid},
{518, 595, invalid, invalid},
{519, 553, invalid, invalid},
{520, 540, 526, 546},
{invalid, invalid, 521, 530},
{522, 529, 524, 533},
{6, 0, 0, 0},
{6, 6, 0, 0},
{6, 0, 6, 0},
{6, 6, invalid, invalid},
{527, 537, invalid, invalid},
{528, 536, invalid, invalid},
{6, 0, invalid, invalid},
{0, 0, 0, 0},
{531, 532, 534, 535},
{0, 6, 0, 6},
{0, 6, 0, 6},
{0, 0, 0, 0},
{0, 6, 0, 6},
{0, 6, 0, 0},
{0, 0, invalid, invalid},
{538, 539, invalid, invalid},
{0, 6, invalid, invalid},
{0, 0, invalid, invalid},
{invalid, invalid, 541, 550},
{542, 543, 544, 545},
{6, 6, 0, 0},
{6, 0, 6, 0},
{0, 0, 0, 0},
{6, 0, 6, 0},
{547, 560, invalid, invalid},
{548, 549, invalid, invalid},
{0, 0, invalid, invalid},
{6, 0, invalid, invalid},
{551, 552, 557, 558},
{6, 6, 0, 0},
{6, 6, 0, 6},
{554, 575, 563, 583},
{invalid, invalid, 555, 567},
{556, 566, 559, 569},
{0, 6, 0, 6},
{6, 6, 0, 0},
{6, 6, 0, 6},
{0, 6, 0, 0},
{561, 562, invalid, invalid},
{6, 6, invalid, invalid},
{6, 6, invalid, invalid},
{564, 572, invalid, invalid},
{565, 571, invalid, invalid},
{0, 6, invalid, invalid},
{6, 6, 0, 0},
{568, 574, 570, 579},
{6, 0, 0, 0},
{6, 6, 0, 0},
{6, 0, 6, 0},
{6, 6, invalid, invalid},
{573, 582, invalid, invalid},
{6, 0, invalid, invalid},
{6, 0, 6, 0},
{invalid, invalid, 576, 587},
{577, 578, 580, 581},
{0, 6, 0, 6},
{0, 6, 0, 6},
{6, 6, 0, 0},
{6, 6, 0, 6},
{0, 6, 0, 6},
{0, 0, invalid, invalid},
{584, 592, invalid, invalid},
{585, 586, invalid, invalid},
{0, 6, invalid, invalid},
{0, 6, invalid, invalid},
{588, 589, 590, 591},
{6, 6, 0, 0},
{6, 0, 6, 0},
{0, 0, 0, 0},
{6, 0, 6, 0},
{593, 594, invalid, invalid},
{6, 6, invalid, invalid},
{6, 0, invalid, invalid},
{596, invalid, invalid, invalid},
{597, 613, 606, 619},
{invalid, invalid, 598, 601},
{599, 600, 603, 604},
{0, 0, 0, 0},
{0, 6, 0, 6},
{602, 612, 605, 616},
{0, 6, 0, 6},
{0, 0, 0, 0},
{0, 6, 0, 6},
{0, 6, 0, 6},
{607, 610, invalid, invalid},
{608, 609, invalid, invalid},
{0, 0, invalid, invalid},
{0, 6, invalid, invalid},
{611, 618, invalid, invalid},
{0, 6, invalid, invalid},
{6, 6, 0, 0},
{invalid, invalid, 614, 623},
{615, 622, 617, 626},
{6, 0, 0, 0},
{6, 6, 0, 0},
{6, 0, 6, 0},
{6, 6, invalid, invalid},
{620, 630, invalid, invalid},
{621, 629, invalid, invalid},
{6, 0, invalid, invalid},
{0, 6, 0, 0},
{624, 625, 627, 628},
{6, 0, 6, 0},
{0, invalid, 0, invalid},
{0, 0, 0, 0},
{6, 6, 6, 0},
{0, invalid, 0, invalid},
{0, 6, invalid, invalid},
{631, 632, invalid, invalid},
{6, 0, invalid, invalid},
{0, invalid, invalid, invalid},
};
uint64_t nodeNum = 633;

Image *map;
Bitmap *screen;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void paint(HDC hdc);
uint64_t pos2rand(uint64_t x, uint64_t y);
void put(uint64_t x, uint64_t y, uint64_t v);
uint64_t get(uint64_t x, uint64_t y);
//void makeFlag();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    //makeFlag();

    if (IsDebuggerPresent())
    {
        MessageBox(NULL, _T("DO NOT DEBUG"), _T("DO NOT DEBUG"), MB_OK | MB_ICONERROR);
        return 0;
    }

    ULONG_PTR token;
    GdiplusStartupInput input;
    GdiplusStartup(&token, &input, NULL);

    map = new Image(L"map.png");
    if (map->GetLastStatus() != Ok)
    {
        MessageBox(NULL, _T("can't open map.png"), _T("error"), MB_OK);
        return 0;
    }
    screen = new Bitmap(W*PS, H*PS, PixelFormat24bppRGB);

    WNDCLASS wndclass = {};
    wndclass.style = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = _T("desert");
    RegisterClass(&wndclass);
    
    DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    RECT rect = {0, 0, W*PS, H*PS};
    AdjustWindowRect(&rect, style, FALSE);

    HWND hWnd = CreateWindow(
        _T("desert"),
        _T("çªîôÇÃíÜÇÃ1ñ{ÇÃÉtÉâÉO"),
        style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        hInstance,
        NULL);
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (true)
    {
        BOOL result = GetMessage(&msg, NULL, 0, 0);
        if (result==0 || result==-1)
            break;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    delete map;
    delete screen;

    GdiplusShutdown(token);

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        paint(hdc);
        EndPaint(hWnd, &ps);
        return 0;
    }
    case WM_KEYDOWN:
        switch (wParam)
        {
        case 'W':
            put(currentX, currentY, 2);
            put(currentX-1, currentY, 1);
            put(currentX+1, currentY, 1);
            put(currentX, currentY-1, 1);
            put(currentX, currentY+1, 1);
            break;
        case 'D':
            put(currentX, currentY, 0);
            break;
        case 'R':
            put(currentX, currentY, 3);
            break;
        case 'T':
            put(currentX, currentY, 6);
            break;
        case 'X':
            put(currentX, currentY, 0);
            break;
        case VK_UP:
            currentY--;
            break;
        case VK_RIGHT:
            currentX++;
            break;
        case VK_DOWN:
            currentY++;
            break;
        case VK_LEFT:
            currentX--;
            break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
        }
        InvalidateRect(hWnd, NULL, FALSE);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

void paint(HDC hdc)
{
    struct OASIS
    {
        uint64_t x, y, r1, r2;
    };

    vector<OASIS> oasis;

    for (uint64_t y=currentY-H/2-5-1; y<=currentY+H/2+5+1; y++)
    for (uint64_t x=currentX-W/2-5-1; x<=currentX+W/2+5+1; x++)
    {
        uint64_t rand = pos2rand(x, y);
        uint64_t p = rand%128; rand/=128;
        if (p == 0)
        {
            OASIS o;
            o.x = x;
            o.y = y;
            o.r1 = rand%4+1; rand/=4;
            if (o.r1 > 2)
                o.r2 = rand%(o.r1-1)+1, rand/=o.r1-1;
            else
                o.r2 = 0;
            oasis.push_back(o);
        }
    }

    uint64_t field[H+2][W+2] = {};
    for (uint64_t dy=0; dy<H+2; dy++)
    for (uint64_t dx=0; dx<W+2; dx++)
    {
        uint64_t x = dx + currentX - W/2 - 1;
        uint64_t y = dy + currentY - H/2 - 1;

        uint64_t t = get(x, y);
        if (t != invalid)
        {
            field[dy][dx] = t;
            continue;
        }

        for (const OASIS &o: oasis)
        {
            uint64_t r = (x-o.x)*(x-o.x) + (y-o.y)*(y-o.y);
            if (r < o.r1*o.r1)
                field[dy][dx] = 1;
            if (r < o.r2*o.r2)
                field[dy][dx] = 2;
        }

        uint64_t rand = pos2rand(x, y) >> 32;
        if (rand%256==0)
            field[dy][dx] += 1*3;
        if (rand%256==1)
            field[dy][dx] += 2*3;
    }

    Graphics g(screen);

    const static int dirx[] = {0, 1, 0, -1};
    const static int diry[] = {-1, 0, 1, 0};

    for (uint64_t y=0; y<H; y++)
    for (uint64_t x=0; x<W; x++)
    {
        uint64_t idx = field[y+1][x+1]%3;
        uint64_t subIdx = 0;
        for (uint64_t d=0; d<4; d++)
            if (field[y+1][x+1]%3 == field[y+diry[d]+1][x+dirx[d]+1]%3)
                subIdx |= 1LL<<d;

        g.DrawImage(map, INT(x*PS), INT(y*PS),
            INT((idx==1 ? 0 : (idx==0 ? 1 : 5) + subIdx%4) * PS),
            INT((idx==1 ? 0 : subIdx/4) * PS),
            PS, PS, Unit::UnitPixel);

        if (field[y+1][x+1]/3==1)
            g.DrawImage(map, INT(x*PS), INT(y*PS), 0, 1*PS, PS, PS, Unit::UnitPixel);
        if (field[y+1][x+1]/3==2)
            g.DrawImage(map, INT(x*PS), INT(y*PS), 0, 2*PS, PS, PS, Unit::UnitPixel);
        if (x==W/2 && y==H/2)
            g.DrawImage(map, INT(x*PS), INT(y*PS), 0, 3*PS, PS, PS, Unit::UnitPixel);
    }

    WCHAR text[256];
    wsprintfW(text, L"%I64u, %I64u", currentX, currentY);

    Font font(L"ÇlÇrÉSÉVÉbÉN", 10);
    SolidBrush brush1(Color(0, 0, 0));
    SolidBrush brush2(Color(255, 0, 0));
    g.DrawString(text, lstrlenW(text), &font, PointF(5, 5), &brush1);
    g.DrawString(text, lstrlenW(text), &font, PointF(4, 4), &brush2);

    Graphics(hdc).DrawImage(screen, 0, 0);
}

uint64_t pos2rand(uint64_t x, uint64_t y)
{
    uint64_t t = x + 123456789;
    for (uint64_t i=0; i<10; i++)
        t ^= t << 13,
        t ^= t >> 7,
        t ^= t << 17;
    t += y + 987654321;
    for (uint64_t i=0; i<10; i++)
        t ^= t << 13,
        t ^= t >> 7,
        t ^= t << 17;
    return t & 0x7fffffffffffffffLL;
}

void put(uint64_t x, uint64_t y, uint64_t v)
{
    uint64_t c = 0;
    for (uint64_t s=0x8000000000000000ULL; s>1ULL; s/=2)
    {
        uint64_t t = (y>=s ? 2 : 0) + (x>=s ? 1 : 0);
        if (node[c][t] == invalid)
        {
            if (nodeNum >= MAX_NODE)
                return;
            node[c][t] = nodeNum;
            node[nodeNum][0] = invalid;
            node[nodeNum][1] = invalid;
            node[nodeNum][2] = invalid;
            node[nodeNum][3] = invalid;
            nodeNum++;
        }
        c = node[c][t];
        x %= s;
        y %= s;
    }
    node[c][y*2+x] = v;
}

uint64_t get(uint64_t x, uint64_t y)
{
    uint64_t c = 0;
    for (uint64_t s=0x8000000000000000ULL; s>1ULL; s/=2)
    {
        uint64_t t = (y>=s ? 2 : 0) + (x>=s ? 1 : 0);
        if (node[c][t] == invalid)
            return invalid;
        c = node[c][t];
        x %= s;
        y %= s;
    }
    return node[c][y*2+x];
}

//void makeFlag()
//{
//    int C[16][5][5] =
//    {{
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,0,0,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//    }, {
//        {0,0,0,1,0},
//        {0,0,0,1,0},
//        {0,0,0,1,0},
//        {0,0,0,1,0},
//        {0,0,0,1,0},
//    }, {
//        {1,1,1,1,0},
//        {0,0,0,1,0},
//        {1,1,1,1,0},
//        {1,0,0,0,0},
//        {1,1,1,1,0},
//    }, {
//        {1,1,1,1,0},
//        {0,0,0,1,0},
//        {1,1,1,1,0},
//        {0,0,0,1,0},
//        {1,1,1,1,0},
//    }, {
//        {1,0,0,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//        {0,0,0,1,0},
//        {0,0,0,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,0,0},
//        {1,1,1,1,0},
//        {0,0,0,1,0},
//        {1,1,1,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,0,0},
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,0,0,1,0},
//        {0,0,0,1,0},
//        {0,0,0,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//        {0,0,0,1,0},
//        {1,1,1,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,0,0},
//        {1,1,1,0,0},
//        {1,0,0,0,0},
//        {1,0,0,0,0},
//    }, {
//        {1,0,0,0,0},
//        {1,0,0,0,0},
//        {1,0,0,0,0},
//        {1,0,0,0,0},
//        {1,1,1,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//        {1,0,0,1,0},
//        {1,0,0,1,0},
//    }, {
//        {1,1,1,1,0},
//        {1,0,0,0,0},
//        {1,0,1,1,0},
//        {1,0,0,1,0},
//        {1,1,1,1,0},
//    }, {
//        {0,1,1,0,0},
//        {0,1,0,0,0},
//        {1,1,0,0,0},
//        {0,1,0,0,0},
//        {0,1,1,0,0},
//    }, {
//        {0,1,1,0,0},
//        {0,0,1,0,0},
//        {0,0,1,1,0},
//        {0,0,1,0,0},
//        {0,1,1,0,0},
//    }};
//
//    int flag1[22] = {10, 11, 12, 13, 14, 9, 7, 2, 9, 5, 1, 2, 2, 1, 6, 7, 2, 7, 0, 8, 7, 15};
//    int flag2[22] = {10, 11, 12, 13, 14, 8, 7, 0, 3, 2, 1, 9, 6, 1, 7, 3, 5, 4, 0, 1, 6, 15};
//    uint64_t x1 = 16819585654921967928ULL;
//    uint64_t y1 =  9709471222094771744ULL;
//    uint64_t x2 =  7088916131484792129ULL;
//    uint64_t y2 =  3638475783989113732ULL;
//
//    for (int f=0; f<22; f++)
//        for (int y=0; y<5; y++)
//        for (int x=0; x<5; x++)
//            put(x1+f*5+x, y1+y, C[flag1[f]][y][x]*3);
//    
//    for (int f=0; f<22; f++)
//        for (int y=0; y<5; y++)
//        for (int x=0; x<5; x++)
//            put(x2+f*5+x, y2+y, C[flag2[f]][y][x]*6);
//
//    printf("%lld\n", nodeNum);
//    for (int i=0; i<nodeNum; i++)
//        printf("{%llu, %llu, %llu, %llu},\n", node[i][0], node[i][1], node[i][2], node[i][3]);
//}
