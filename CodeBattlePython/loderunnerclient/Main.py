#from loderunnerclient.LodeRunnerClient import GameClient

from ctypes import cdll
lib = cdll.LoadLibrary('./cyth/libcyth.so')


from LodeRunnerClient import GameClient
import random
import logging
import os

#from loderunnerclient.internals.actions import LoderunnerAction
#from loderunnerclient.internals.board import Board

from internals.actions import LoderunnerAction
from internals.board import Board
from internals.element import _ELEMENTS


logging.basicConfig(format='%(asctime)s %(levelname)s:%(message)s',
                    level=logging.INFO)


b=False
i=0
def turn(gcb: Board, strboard=""):
    global b
    global i
    i+=1
    if(i>4):
        qq=lib.foo(strboard)
        i=0
    #qq=lib.foo(strboard)
    print(strboard)
    brd = Board(strboard)
    print(brd.get_barriers())
    print(brd.get_my_position())
    #brd.print_board()
    #print(brd.get_my_position())
    #os.system("echo \""+strboard+"\" >f.txt")
    print(brd.get_gold_positions())
    #print(brd.to_string())
    #print(lib.foo())
    b=not b
    return LoderunnerAction.DRILL_LEFT if b else LoderunnerAction.DRILL_RIGHT
    action_id = random.randint(0, len(LoderunnerAction)-1)
    return list(LoderunnerAction)[action_id]

if __name__ == '__main__':
    url = "codingdojo2019.westeurope.cloudapp.azure.com"
    userId="jlebg3nx316vg6qfo6q1"
    userCode="7303406248495085684"


    b="☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼                             ~~~~~~~~~          (~~~~~~~☼☼##H########################H#H     @ H##########H    $  ☼☼( H                        H######H  H      (   H#☼☼☼☼☼#☼☼H☼☼#☼☼H    H#########H (   H#&    H#####H#####H##((~~~~~☼☼H     H    H         H#####H#)    H ~   H  @  H @ЄЄ((  (☼☼H#☼#☼#H    H         H  ~~~ #####H#     H     H    ЄЄ(((☼☼H  ~  HЄ~Є~H~~~~~~   H         & H   H######H##     @ЄЄ(☼☼H  @  H    H     H###☼☼☼☼☼☼H☼ $  H~~~H      H         $#☼☼H   ( H    H#####H         H     H      H#########H $ @$☼☼☼###☼##☼##☼H         H###H##    H##     H#       ##     ☼☼☼###☼~~~~  H   & &   H   H######H######### H###H #####H#☼☼☼$((☼      H   ~~~~~~H   H      H          H# #H      H ☼☼########H###☼☼☼☼     H  ############   ###### ##########☼☼        H            H                      ((         @☼☼H##########################H########~~~####H############☼☼H                 ~~~      H    @          H $          ☼☼#######H#######            H###~~~~      ############H  ☼☼&      H~~~~~~~~~~         H                         H  ☼☼       H    ##H   #######H##########~~~~~~>H######## H  ☼☼ ((    H    ##H (        H     $   &       H         H  ☼☼##H#####    ########H#######~~~~  ~~~#########>~~~~  H  ☼☼  H      (          H    @                       ~~~ЄH $☼☼#########H##########H  $ @   #☼☼☼☼☼☼#   ☼☼☼☼☼☼☼      H  ☼☼((&      H          H        ~ (((((~     (          H  ☼☼☼☼&      H~~Є~~~~~~~H       « ######   ###########   H  ☼☼    H###### &       #######H           ~~~~~~~~~~~~~~H  ☼☼H☼  H         (            H  H####H )               H  ☼☼H☼☼#☼☼☼☼☼☼☼☼☼☼☼☼###☼☼☼☼☼☼☼☼H☼☼☼☼☼☼☼☼ ☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼#☼☼H $ @&       ~~H~~~~☼☼☼☼☼☼☼H☼☼☼☼☼☼☼       H @ ~~~~~~~~~H☼☼H~~~~  ###### &H       & H☼H☼H    (   ####H  ☼    $    H☼☼H       (   @  ##H#######H☼H☼H######H  &  ###☼☼☼☼☼☼☼☼ ~H☼☼H#########       H&   ~~~H☼H☼H~~~   H~~~~~ ##&(((((@ ~ H☼☼H        ###H####H##H (   ☼H☼       H     ###☼☼☼☼☼☼ ~  H☼☼H       &   H   @  #######☼H☼#####  H##### $ ~~~~~~~ ~ H☼☼~ЄЄ~~~~~~~~~H       H~~~~~☼H☼~~~~~  H             ~ ~  H☼☼  &  H              H ((($☼H☼     ##########H (        H☼☼ ### #############H H#####☼H☼               H ######## H☼☼H   (@            H     $$☼H☼#######   (    H @  (     H☼☼H#####         H##H####                ###H#########   H☼☼H      H######### H   ############        H            H☼☼H##    H          H~~~~~~                 H #######H## H☼☼~~~~#####H#   ~~~~H         ########H   & H    $ & H   H☼☼         H ►      H      ~~~~~~~~   H     H        H   H☼☼   ####### H   «######H##        ##############    H  (H☼☼           H(    $$   H        ~~~~~           ##H#####H☼☼H (  ###########H     H#####H      ( @H##H       H &   H☼☼H###            H(    H     ###########  ##H###  H     H☼☼H  ######  ##H######  H          (  $      H   ##H###  H☼☼H            H ~~~~~##H###H  @  #########H##           H☼☼    H########H#       H   ######         H    (        H☼☼ ###H        H         ~~~~~H      ##H###H####H###     H☼☼    H########H#########     H  @  (  H        H        H☼☼H   H                       H     (  H        H        H☼☼H  ####H######         #####H########H##      H#####   H☼☼H      H      H#######Q   (       (           H        H☼☼##############H    )  H#################################☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼☼"
    #br=Board(b)
    #br.print_board()
    #str = lib.foo(b)
    #print(":")
    for c in _ELEMENTS:
        print(c,_ELEMENTS[c])



    gcb = GameClient(url, userId, userCode)
    gcb.run(turn)

    print(str)
