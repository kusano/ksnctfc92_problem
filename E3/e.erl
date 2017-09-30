-module(e).

-behaviour(gen_server).

-export([
    calc_e/1,
    get_flag/0,
    start_link/0,
    input_pin/2
]).

-export([
    init/1,
    handle_call/3,
    handle_cast/2,
    handle_info/2,
    terminate/2,
    code_change/3
]).

-record(state, {stage}).

calc_e(X) ->
    calc_e(X, 1.0, 1.0, 1, 0.0).

calc_e(_X, _Exp, _Fact, 100, Acc) ->
    Acc;
calc_e(X, Exp, Fact, K, Acc) ->
    calc_e(X, Exp*X, Fact*K, K+1, Acc+Exp/Fact).

get_flag() ->
    get_flag(8, []).

get_flag( 0, Acc) -> get_flag(18, [ 90|Acc]);
get_flag( 1, Acc) -> get_flag(19, [ 65|Acc]);
get_flag( 2, Acc) -> get_flag(16, [103|Acc]);
get_flag( 3, Acc) -> get_flag(15, [ 70|Acc]);
get_flag( 4, Acc) -> get_flag(13, [120|Acc]);
get_flag( 5, Acc) -> get_flag(22, [123|Acc]);
get_flag( 6, Acc) -> get_flag(17, [115|Acc]);
get_flag( 7, Acc) -> get_flag(11, [ 66|Acc]);
get_flag( 8, Acc) -> get_flag(10, [125|Acc]);
get_flag( 9, Acc) -> get_flag( 5, [ 56|Acc]);
get_flag(10, Acc) -> get_flag(20, [118|Acc]);
get_flag(11, Acc) -> get_flag( 2, [100|Acc]);
get_flag(12, Acc) -> get_flag(21, [ 67|Acc]);
get_flag(13, Acc) -> get_flag(14, [ 68|Acc]);
get_flag(15, Acc) -> list_to_binary(Acc);
get_flag(14, Acc) -> get_flag( 9, [ 89|Acc]);
get_flag(16, Acc) -> get_flag( 6, [117|Acc]);
get_flag(17, Acc) -> get_flag(12, [ 65|Acc]);
get_flag(18, Acc) -> get_flag( 4, [100|Acc]);
get_flag(19, Acc) -> get_flag( 3, [ 76|Acc]);
get_flag(20, Acc) -> get_flag( 7, [ 69|Acc]);
get_flag(21, Acc) -> get_flag( 0, [ 84|Acc]);
get_flag(22, Acc) -> get_flag( 1, [ 71|Acc]).

start_link() ->
    gen_server:start_link(?MODULE, [], []).

input_pin(Pid, Pin) ->
    gen_server:call(Pid, {input_pin, Pin}).

init([]) ->
    {ok, #state{stage = 0}}.

handle_call({input_pin, Pin} , _From, #state{stage = Stage} = State) ->
    if
        Stage==0, Pin==9717;
        Stage==1, Pin==1498;
        Stage==2, Pin==8030;
        Stage==3, Pin==3280;
        Stage==4, Pin==0572;
        Stage==5, Pin==8628;
        Stage==6, Pin==4294;
        Stage==7, Pin==8001 ->
            case Stage of
                7 ->
                    {reply, f(), State#state{stage = 0}};
                _ ->
                    {reply, ok, State#state{stage = Stage+1}}
            end;
        true ->
            {reply, ok, State#state{stage = 0}}
    end;
handle_call(_, _From, State) ->
    {reply, error, State}.

handle_cast(_, State) ->
    {noreply, State}.

handle_info(_, State) ->
    {noreply, State}.

terminate(_, _) ->
    ok.

code_change(_OldVsn, State, _Extra) ->
    {ok, State}.

f() ->
    list_to_binary([trunc(calc_e(X)) || X <- [
        4.2556127098182230,
        4.3372907408324899,
        4.1820501426412067,
        4.2696974496999616,
        4.8162411560680320,
        4.4485163759427149,
        4.2696974496999616,
        4.5053498507058807,
        4.4127982933406349,
        4.7578912730057557,
        4.1820501426412067,
        4.7916497529307094,
        3.9415818076696905,
        4.7916497529307094,
        4.7140245909001735,
        4.4942386252808095,
        4.4367515343631281,
        4.7749129605751861,
        4.2835865618606288,
        4.3630986247883632,
        4.7405748229942946,
        4.8323057585718390
    ]]).
