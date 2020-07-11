#include "FCatDog.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGameSummary();
bool AskToPlayAgain();
FCatDog CDGame;

int main()
{
    bool bWantsToPlayAgain = false;
    
    do {
    PrintIntro();
    PlayGame();
    bWantsToPlayAgain = AskToPlayAgain();
    }
    while (bWantsToPlayAgain);
    return 0;
}


void PrintIntro()
{
    CDGame.Reset();

    std::cout << "\nWelcome to the GAME :D\n";
    std::cout << "Here is a little explanation how this game works:\n";
    std::cout << "The count of dogs indicates that the letters and their position are guessed correctly.\n";
    std::cout << "The count of cats indicates that some letters are contained in the word, but their position is wrong.\n";
    std::cout << "Cats are not counted if dogs are in place.\n";
    std::cout << "\n";
    std::cout << "       Dog              Cat \n";
    std::cout << "\n";
    std::cout << "    , '.-.'.           _  ,/| \n";
    std::cout << "     '\\~ o/` ,,      '\\`o.O'   _ \n";
    std::cout << "      { @ } f        = (_*_) = (   \n";
    std::cout << "     / `-'\\$            )U(  _)  \n";
    std::cout << "    (_ / -\\_)          /   \\(  \n";
    std::cout << "                      (/ `-'\\)  \n";
    std::cout << "\n";
    std::cout << "Can you guess the " << CDGame.GetHiddenWordLength();
    std::cout << " letter anime character I'm thinking of?\n";
    return;
}

void PlayGame()
{
    
    int32 MaxTries = CDGame.GetMaxTries();
    
    while (!CDGame.IsGameWon() && CDGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetGuess();
        FCatDogCount CatDogCount = CDGame.SubmitValidGuess(Guess);
        
        std::cout << "Dogs = " << CatDogCount.Dogs;
        std::cout << " Cats = " << CatDogCount.Cats << std::endl;
        std::cout << std::endl;
       
    }

    PrintGameSummary();
    return; 
}


FText GetGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess = "";
    do {
        int32 CurrentTry = CDGame.GetCurrentTry();
        std::cout << "Try " << CurrentTry << " of " << CDGame.GetMaxTries();
        std::cout << ".\nEnter Your Guess: ";

        std::getline(std::cin, Guess);
    
        Status = CDGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << CDGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please don't repeat any letters.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please no uppercase and numbers.";
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }
    while (Status != EGuessStatus::OK);
    return Guess;
}


bool AskToPlayAgain()

{
    std::cout << "Do you want to play again?(y/n) ";
    std::string Response = "";
    std::getline (std::cin, Response);
    
    return (Response[0] == 'y');
    
}


void PrintGameSummary() {
    FText Go = CDGame.MyHiddenWord;

    if (CDGame.IsGameWon() && Go == "goku") {
        std::cout << "\n";
        std::cout << "                   `\\-.   `\n";
        std::cout << "                      \\ `.  `\n";
        std::cout << "                       \\  \\ |\n";
        std::cout << "              __.._    |   \\.       S O N - G O K U\n";
        std::cout << "       ..---~~     ~ . |    Y\n";
        std::cout << "         ~-.          `|    |\n";
        std::cout << "            `.               `~~--.\n";
        std::cout << "              \\                    ~.\n";
        std::cout << "               \\                     \\__. . -- -  .\n";
        std::cout << "         .-~~~~~      ,    ,            ~~~~~~---...._\n";
        std::cout << "      .-~___        ,'/  ,'/ ,'\          __...---~~~\n";
        std::cout << "            ~-.    /._\_( ,(/_. 7,-.    ~~---...__\n";
        std::cout << "           _...>-  P""6=`_/\"6\"~   6)    ___...--~~~\n";
        std::cout << "            ~~--._ \\`--') `---'   9'  _..--~~~\n";
        std::cout << "                  ~\\ ~~/_  ~~~   /`-.--~~\n";
        std::cout << "                    `.  ---    .'   \\_\n";
        std::cout << "                      `. \" _. - '     | ~-.,-------._\n";
        std::cout << "                  ..._../~~   ./       .-'    .-~~~-.\n";
        std::cout << "            ,--~~~ ,'...\\` _./.----~~.'/    /'       `-\n";
        std::cout << "        _.-(      |\\    `/~ _____..-' /    /      _.-~~`.\n";
        std::cout << "       /   |     /. ^---~~~~       ' /    /     ,'  ~.   \\\n";
        std::cout << "      (    /    (  .           _ ' /'    /    ,/      \\   )\n";
        std::cout << "      (`. |     `\\   - - - - ~   /'      (   /         .  |\n";
        std::cout << "       \\.\\|       \            /'        \\  |`.           /\n";
        std::cout << "       /.'\\\\      `\\         /'           ~-\\         .  /\\\n";
        std::cout << "      /,   (        `\\     /'                `.___..-      \\\n";
        std::cout << "     | |    \\         `\\_/'                  //      \\.     |\n";
        std::cout << "     | |     |                 _Seal_      /' |       |     |\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "Congratulations, YOU WON!!!\n";
        std::cout << "\n";
        std::cout << "    , '.-.'.           _  ,/| \n";
        std::cout << "     '\\~ o/` ,,      '\\`o.O'   _ \n";
        std::cout << "      { @ } f        = (_*_) = (   \n";
        std::cout << "     / `-'\\$            )U(  _)  \n";
        std::cout << "    (_ / -\\_)          /   \\(  \n";
        std::cout << "                      (/ `-'\\)  \n";
        std::cout << "\n";
    }

    if (CDGame.IsGameWon() && Go == "lum") {
        std::cout << "                                                              .---..._\n";
        std::cout << "                                                        ..--\"\"         \" - .\n";
        std::cout << "                                                   ..-\"\"\"                 \".\n";
        std::cout << "                                               ..-\"\"                        \"\n";
        std::cout << "                                            .-\"\n";
        std::cout << "                                         .-\"      ... -_\n";
        std::cout << "                                     .=\"   _..-\" F   . - \"-.....___-..\n";
        std::cout << "                                     \"L_ _-'    .\"  j\"  .-\":   /\"-._ \"-\n";
        std::cout << "                                        \"      :  .\"  j\" : : | \"\" \".\n";
        std::cout << "                    ......---------\"\"\"\"\"\"\"\"\"\"\"-:_     |   |\n";
        std::cout << "          ...---\"\"\"\"                             -.   f   | \"\n";
        std::cout << "  ...---\"\"       . ..----\"\"\"\"\"\"\"\"..                \". - ... f  \".\n";
        std::cout << "         ..---\"\"\"       ..---\"\"\"\"\"\"\"\"-..--\"\"\"\"\"\"\"\"\"^^::            |. \" - .    .\n";
        std::cout << "     .--\"           .mm::::::::::::::::::::::::::...  \"\"L           |x   \".\n";
        std::cout << "   -\"             mm;;;;;;;;;;XXXXXXXXXXXXX:::::::::::.. |           |x.   - \n";
        std::cout << "xF        -._ .mF;;;;;;XXXXXXXXXXXXXXXXXXXXXXXXXX:::::::|            |X:.  \"\n";
        std::cout << "j         |   j;;;;;XXX#############################::::::|            XX::::\n";
        std::cout << "|          |.#;::XXX##################################::::|            |XX:::\n";
        std::cout << "|          j#::XXX#######################################::             XXX::\n";
        std::cout << "|         .#:XXX###########################################             |XX::\n";
        std::cout << "|         #XXX##############################XX############Fl             XXX:\n";
        std::cout << "|        .XXX###################XX#######X##XXX###########Fl             lXX:\n";
        std::cout << "|       #XX##################XXX######XXXXXXX###########F j             lXXX\n";
        std::cout << "|       #X#########X#X#####XXX#######XXXXXX#######XXX##F  jl            XXXX\n";
        std::cout << "|       #X#######XX#\"  V###XX#' ####XXXXXX##F\"T##XXXXXX.  V   /  .    .#XXXX\n";
        std::cout << "|       #########\"     V#XX#'  \"####XXXX##.---.##XXXXXX.    /  /  / .##XXXX\n";
        std::cout << "  |       \"######X' .--\"\" \"V##L   #####XXX#\"      \"###XXXX. .\"  /  / .###XXXX\n";
        std::cout << "  |         #####X \".m###m##L   ####XX#      m###m\"###XX#   /  / .#####XXX\n";
        std::cout << "   |         \"###X.mF\"\"   \"y     #####     mX\"   \"Y#\" ^ ####X / .######XXX\n";
        std::cout << "   |           \"T#   #\"        #     ####    X\"       \"F\"\"###XX\"###########XX\n";
        std::cout << "   |             L  d\"     dXX  xm   \"^##L mx     dXX  YL-\"##XX\"S\"\"##########\n";
        std::cout << "    |            xL J     Xd%    T      \"\"  T    XdX    L. \"##XS.f | #########\n";
        std::cout << "    |             BL      X## X                  X## X      T#SS\" | #########\n";
        std::cout << "    |              #L     X%##X                  X%##X|     j#SSS /##########\n";
        std::cout << "     |              #L  ._ TXXX-\"           \"-._  XXXF.-    ###SS\\###########\n";
        std::cout << "     |              ##   \"\"\"\"\"                  \"\"\"\"\"\"      ##DS.\\###########\n";
        std::cout << "     |              TF                                      ##BBS.T#########F\n";
        std::cout << "      |             #L           ---                        ###BBS.T########'\n";
        std::cout << "      |            '##            \"\"                     jL|###BSSS.T#######\n";
        std::cout << "       |          '####             ______              .:#|##WWBBBSS.T####F\n";
        std::cout << "      J L        '######.            \\___/            _c::#|###WWWBSSS|####\n";
        std::cout << "     J ;;       '########m            \\_/            c:::'#|###WWWBBSS.T##\"\n";
        std::cout << "    J ;;;L      :########.:m.          _          _cf:::'.L|####WWWWSSS|#\"\n";
        std::cout << "  .J ;;;;B      ########B....:m..             _,c%%%:::'...L####WWWBBSSj\n";
        std::cout << " x  ;;;;dB      #######BB.......##m...___..cc%%%%%::::'....|#####WWBBDS.|\n";
        std::cout << "\";;;;; ABB#     #######BB........##j % %%%%%%%%%%%%%:::'..... #####WWWWDDS|\n";
        std::cout << ".;;;;;dBBB#     #######BB.........%%%%%%%%%%%%%%%:::'...   j####WWWWWBDF\n";
        std::cout << ";;;;;BBB####    ######BBB.........%%%%%%%%%%%%%%:::'..     #####WWWWWWS\n";
        std::cout << ";;;;dBBB####    ######BBB..........^%%%%%%%%%%:::\"         #####WWWWWWB\n";
        std::cout << ";;;:BBB######   X#####BBB\"...........\"^YYYYY::\"            #####WWWWWWW\n";
        std::cout << ";;.BB#########  X######BBB........:''                      #####WWWWWWW\n";
        std::cout << ";;BB##########L X######BBB.......mmmm..                 ..x#####WWWWWWB.\n";
        std::cout << ";dBB########### X#######BB.....        \" - ._           x\"\"  #####WWWWWWBL\n";
        std::cout << ";BBB###########L X######BB...              \" - ######WWWWBBBL\n";
        std::cout << "BBB#############. ######BBB.                                #####WWWWBBBB\n";
        std::cout << "BBB############## X#####BBB                                 #####WWWWWBBB\n";
        std::cout << "BBB############### T#####BB                                  #####WWWBBB     :\n";
        std::cout << "BB################# T###BBP                                   #####WWBB\"    .#\n";
        std::cout << "BB##################..W##P                                      ###BBB\"    .##\n";
        std::cout << "BB###################..l                                         \"WW\"      ###\n";
        std::cout << "BB####################j ___                                        \" l    j###\n";
        std::cout << "BBB##################J_-   \"\"\" - ..             ':::'   . - \"\"\"\"\"\"\"\"\"\" - .l  .####\n";
        std::cout << "BBB######B##########J########    \" - .           ::'  -\" ..mmm####mm..\"-.< #####\n";
        std::cout << "MCL-5/7/88 BBB#####J############    \" - _        : | \" .###############mmLlR####\n";
        std::cout << "BBBBBBBBBBBBBBB###/         #######    -.     .:| \".#####F ^ ^^P ^ ^\"\"\"^^^Y#lT####\n";
        std::cout << "BBBBBBBBBBBBBBBBBj|####mm        ######xx-...:::|\" ###f      .....      \"#T###\n";
        std::cout << "BBBBBBBBBBBBBBBBjj##########mm..           \":::.\"j##F  .mm#########mmm.. Yj###\n";
        std::cout << "BBBBBBBBBBBBBBBB|^WWWSRR############mmmmm xx \"\"\"mjF.mm####################j###\n";
        std::cout << "BBBBBBBBBBBBBBBB|                      ######mmmmmm#######################j###\n";
        std::cout << "BBBBBBBBBBBBBBBBY#m...   ..mmm##########PPPPP#####m..                    lj###\n";
        std::cout << "BBBBBBBBBBBBBBBBB2##############^^\"\"     ..umF^^^Tx ^##mmmm........mmmmmmlj###\n";
        std::cout << "BBBBBBBBBBBBBBBBBJT######^^^\"\"     .mm##PPPF\"....\"m.  \" ^ ^###############lj####\n";
        std::cout << "BBBBBBBBBBBBBBBBB##^L         .mmm###PPP............\"m..    \"\"\"\" ^ ^^^^\"\" lj####\n";
        std::cout << "BBBBBBBBBBBBBBBB#####Y#mmx#########P..................\" ^ :muuuummmmmm### ^ .#####\n";
        std::cout << "BBBBBBBBBBBBBBBB#####::Y##mPPPPF^\"....... | .............. \"\" ^ ^###### ^ ^\"...#####\n";
        std::cout << "BBBBBBBBBBBBBB########..................F............      \\     ........#####\n";
        std::cout << "BBBBBBBBBBBBB#########.................|..........          :       ....l#####\n";
        std::cout << "BBBBBBBBBBBB###########...............F.........             \\        ..######\n";
        std::cout << "BBBBBBBBBBB#############.............|........                :         dA####\n";
        std::cout << "BBBBBBBBBB##############.....................                           kM####\n";
        std::cout << "BBBBBBBBB################..................                             k#####\n";
        std::cout << "BBBBBBB##################................                               k#####\n";
        std::cout << "BBBBB#####################.............                                 t#####\n";
        std::cout << "BB########################............                                  \"E####\n";
        std::cout << "B########################F............                           .       \"####\n";
        std::cout << "#########################............'      |                    ..       \"L##\n";
        std::cout << "########################F............                           ...        \"L#\n";
        std::cout << "#######################F............'                           .....       \"#\n";
        std::cout << "######################F.............                           .......       \"\n";
        std::cout << "#####################$..............                         .........\n";
        std::cout << "#####################lmmm.............                      ...........   ..m#\n";
        std::cout << "####################j########mmmm.............            ......mmmmmm########\n";
        std::cout << "###################j###::::;:::::########mmmmmmm##############################\n";
        std::cout << "##################j:::::::;:::::::;;::##############################^^^\"\"\"\"\n";
        std::cout << "##################.mm:::mmm######mmmm:::' ^^^^^^\"\"#######^^\"\"\"\"\n";
        std::cout << "#################F...^m::;::################mmm  .mm\"\"\"\n";
        std::cout << "#################.......m;::::::::::::#########^\"\n";
        std::cout << "################F.........###mmm::::;' .##^\"\"\"\n";
        std::cout << " ##############F...........:#######m.m#\"\n";
        std::cout << "   ############..............':####\n";
        std::cout << "     #########F............mm^\"\"\n";
        std::cout << "       #######..........m^\"\"\n";
        std::cout << "          ####.......%^\"\n";
        std::cout << "             #.....x\"\n";
        std::cout << "             |.x\"\"\n";
        std::cout << "            .-\"\n";
        std::cout << "          .-\n";
        std::cout << "        .-\n";
        std::cout << "      .-\n";
        std::cout << "     -\n";
        std::cout << "   -\"\n";
        std::cout << " -\"\n";
        std::cout << "\"\n";
        std::cout << "                                                                             x\n";
        std::cout << "                                                                             x\n";
        std::cout << "                                                                             x\n";
        std::cout << "                                                                           xx\n";
        std::cout << "                                                                         xx\n";
        std::cout << "                                                                     xxx\"\n";
        std::cout << "                                                                 xxx\"\n";
        std::cout << "                                                           .xxxx\"\n";
        std::cout << "                                                   ___xxx\"\"\n";
        std::cout << "                                             .xxxx\"\"....F\n";
        std::cout << "                \"\"\"\"mmxxxxx          ___xxx^^^..........'\n";
        std::cout << "                   .xx^^^^YYYY###xxx^^.................|\n";
        std::cout << "                .xx^\"        #######x.................. | \n";
        std::cout << "             .xx\"          ###########mx..............f\n";
        std::cout << "           .x^            ##############xx............|\n";
        std::cout << "          j\"             ##############    x..........; \n";
        std::cout << ".........#              ############       #x.........|\n";
        std::cout << "x.......j\"              ##########       ####x.......f\n";
        std::cout << "xxx....#..            ########        #######x......|\n";
        std::cout << "   xxxx.#....         #######        ##########x.....|\n";
        std::cout << "      xxx......       #####         #########   x....|\n";
        std::cout << "         xxx......    ###          #######      #m...|\n";
        std::cout << "           xxx......  ##           ######      ####..|\n";
        std::cout << "             xxx......#.          #####       ######m|\n";
        std::cout << "               xxxx.......        ###        #######Fx\n";
        std::cout << "                   xxx......      #         j#####    m\n";
        std::cout << "                      xx......              ####      Jxm\n";
        std::cout << "                       xxx......           ####      j###Km\n";
        std::cout << "                          xxx.....         ###      j####F  m\n";
        std::cout << "                             xx......       #       ###F    .m\n";
        std::cout << "                               xxx ....            j##F    .###m\n";
        std::cout << "                               m..xx.....          ##F    j#####K^mm.\n";
        std::cout << "                                m...xx......       ##     #####F    ####mm\n";
        std::cout << "                                m .....x......     F     j####F    ########\n";
        std::cout << "                                 m  ......x.....         ###F    J##########\n";
        std::cout << "                                 \"m  ........x....      .#F     ######### ^ ^| \n";
        std::cout << "                                  \"......mmF ^ ^^x....    ##     ###### | \n";
        std::cout << "                                   lL..jF        x.... .F      ####       |\n";
        std::cout << "                                   lTLJF           x....      ####        |\n";
        std::cout << "                                   l::|.            \"....j###       ##\n";
        std::cout << "                                    l....            L....   ###F     x##\n";
        std::cout << "                                     l....       ..m##L...   ##F     j###\n";
        std::cout << "                                     l:...        #####L...  #F     j####\n";
        std::cout << "                                      l....    ####     ...        #####\n";
        std::cout << "                                      \"....              ...       ####F | \n";
        std::cout << "                                       l....              ...     j###F  |\n";
        std::cout << "                                        #...               ....   ###F    |\n";
        std::cout << "                                        \"#...jL.... ##F | \n";
        std::cout << "                                         ##.            .m###L....#F      |\n";
        std::cout << "                                         \"##        ..mm###### .... | \n";
        std::cout << "                                          |                   |...        |\n";
        std::cout << "                                          k                    |...       |\n";
        std::cout << "                                          l                    |...       k\n";
        std::cout << "                                           k                 .m#L...     Jk\n";
        std::cout << "                                           ##            ..mm####L...     k\n";
        std::cout << "                                           ###         d########' L....   |\n";
        std::cout << "                                           l                   |   \" - .__ - \"\n";
        std::cout << "                                           l                   |\n";
        std::cout << "                                           l                  j#\n";
        std::cout << "                                           :                 j##\n";
        std::cout << "                                            k               j##'\n";
        std::cout << "                                            l            .m###k\n";
        std::cout << "                                            l           ###^^\" | \n";
        std::cout << "                                            |                 |\n";
        std::cout << "                                            j               .##\n";
        std::cout << "                                            |              ######\n";
        std::cout << "                                            |==          ##### ####\n";
        std::cout << "                                           .k          #####\"   ####\n";
        std::cout << "                                           l         #####^     ####\n";
        std::cout << "                                           l       ###         ####'\n";
        std::cout << "                                           !                 m###F\n";
        std::cout << "                                           |               ######\n";
        std::cout << "                                           |           mm##m###'\n";
        std::cout << "                                           |.       m########F\n";
        std::cout << "                                           |.    m#######F\" #\n";
        std::cout << "                                           d.   ###        #\n";
        std::cout << "                                          |..             .'\n";
        std::cout << "                                          |..             |\n";
        std::cout << "                                           k..           :\n";
        std::cout << "                                           \\...          F\n";
        std::cout << "                                            |...        #d\n";
        std::cout << "                                            |...       ###\n";
        std::cout << "                                             L...     ####.\n";
        std::cout << "                                             |...    j### |\n";
        std::cout << "                                              L...   ###  |\n";
        std::cout << "                                              T...  j##    k\n";
        std::cout << "                                               \\... ##     |\n";
        std::cout << "                                                 \\...      .\n";
        std::cout << "                                                   \" ^ -____ - \n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "                                                \"Lum\" (from Urusei Yatsura)\n";
        std::cout << "                                                      --- Michael C. Ling\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        }

    if (CDGame.IsGameWon() && Go == "totoro") {
        std::cout << "             ,--\"""\",--.__,---[],-------._         \"\n";
        std::cout << "       ,\"   __,'            \\         \--\"\"\"\"""==;-\"\n";
        std::cout << "     ,\" _,-"  "/---.___     \\       ___\   ,-'',""\n";
        std::cout << "    /,-'      / ;. ,.--'-.__\\  _,-"" ,| `,'   /\"\n";
        std::cout << "   /``\"\"\"\"-._/,-|:\        []\,' ```-/:\;-. `. /\"\n";
        std::cout << "             `  ;:::      ||       /:,;  `-.\"\n";
        std::cout << "                =.,'__,---||-.____',.=\"\n";
        std::cout << "                =(:_      ||__    ):)=\"\n";
        std::cout << "               ,\"::::`----||::`--':::\"._\"\n";
        std::cout << "             ,':::::::::::||::::::::::::'.\"\n";
        std::cout << "    .__     ;:::.-.:::::__||___:::::.-.:::\\     __,\"\n";
        std::cout << "       \"\"\"-;:::( O )::::>_|| _<::::( O )::::-\"\"\"\"\n";
        std::cout << "   =======;:::::`-`:::::::||':::::::`-`:::::\\=======\"\n";
        std::cout << "    ,--\"\";:::_____________||______________::::\"\"----.          , ,\"\n";
        std::cout << "         ; ::`._(    |    |||     |   )_,'::::\_,,,,,,,,,,____/,'_,\"\n";
        std::cout << "       ,;    :::`--._|____[]|_____|_.-'::::::::::::::::::::::::);_\"\n";
        std::cout << "      ;/ /      :::::::::,||,:::::::::::::::::::::::::::::::::::/\"\n";
        std::cout << "     /; ``''''----------/,'/,__,,,,,____:::::::::::::::::::::,\"\"\n";
        std::cout << "     ;/                :);/|_;| ,--.. . ```-.:::::::::::::_,\"\"\n";
        std::cout << "    /;                :::):__,'//\"\"\\. ,--.. \:::,:::::_,\"\"\n";
        std::cout << "   ;/              :::::/ . . . . . . //\"\"\\. \::\":__,\"\"\n";
        std::cout << "   ;/          :::::::,' . . . . . . . . . . .:`::\"\n";
        std::cout << "   ';      :::::::__,'. ,--.. . .,--. . . . . .:`::`\"\n";
        std::cout << "   ';   __,..--'''-. . //\"\"\\. .//\"\"\\ . ,--.. :`:::`\"\n";
        std::cout << "   ;    /  \\ .//\"\"\\ . . . . . . . . . //\"\"\\. :`::`\"\n";
        std::cout << "   ;   /       . . . . . . . . . . . . . . . . .:`::`\"\n";
        std::cout << "   ;   (          . . . . . . . . . . . . . . . ;:::`\"\n";
        std::cout << "   ,:  ;,            . . . . . . . . . . . . . ;':::`\"\n";
        std::cout << "   ,:  ;,             . . . . . . . . . . . . .;`:::\"\n";
        std::cout << "   ,:   ;,             . . . . . . . . . . . . ;`::;`\"\n";
        std::cout << "    ,:  ;             . . . . . . . . . . . . ;':::;`\"\n";
        std::cout << "     :   ;             . . . . . . . . . . . ,':::;\"\n";
        std::cout << "      :   '.          . . . . . . . .. . . .,':::;`\"\n";
        std::cout << "       :    `.       . . . . . . . . . . . ;::::;`\"\n";
        std::cout << "        '.    `-.   . . . . . . . . . . ,-'::::;\"\n";
        std::cout << "          `:_    ``--..___________..--'':::::;'`\"\n";
        std::cout << "             `._::,.:,.:,:_ctr_:,:,.::,.:_;'`\"\n";
        std::cout << "________________`\"\/\"\\/\\/'\"\"\"\"`\\/\"\\/""\\/\"____________________________\"\n";
       std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    if (CDGame.IsGameWon() && Go == "jonathanjoestar") {

        std::cout << "111iiii1iiiiiiiiiiii:::,,,,,,,,::,fC;:;::;::Li;i1iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii1\n";
        std::cout << "iiiiiiiiiiiiiiiiiiii,...:,..,.,,,,1C;;;;;:;1i:iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n";
        std::cout << "11iii;;iiiiiiiiii;,,,,.,;;:,..,,,,,::::1;::fti1:;iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n";
        std::cout << "ttffft1iiiiiiiiiii,.,,:,.,:....,,,,,,,11:;:1if11tiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n";
        std::cout << ",1t::111111iiiii:,,,,.,:..,,,,.,;,,,,,:,::,:11;:;iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n";
        std::cout << "ii,:;:11tttiiii;,....,.::,,,:,.,,:...,,,,.,:i;:,,:iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n";
        std::cout << "t;ii::;i;iii;ii;:,....,..,........:;:.,:,,,....,,;;i;iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n";
        std::cout << ";iiiiii11111111:..........,,;:,.,.;G01i1iit,,,.,.,1LLi;iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii;;iii\n";
        std::cout << "iii;;;;;;i;iii;,,.........,:,,,.,f:1GG,::;1:.,,.,fGGGi;iiiiiiiiiiiiiiiiiiiiii;;iiiiii;;;;;ii;;;;;;;i\n";
        std::cout << "ttt;..,,,,..,,,,,..........,,,.:,G1iGG;;i,:t:,t,tCCC;;iiii;;;iiiii;;::::;;,,,,,,,,:;;;;;;;;;;;;;;;;;\n";
        std::cout << "ii;:;;;;;;:,,::,,,...,,..,,,,,.t1fL,C0C,:tf0;:iiGCG1:;;;;;ii;:;;:,,...::1i,... .,;;:;;::;;;;;;;;;;:,\n";
        std::cout << "ii:::;iii;::i:,::::,.,1,.:;;t;i1:.i;C0CtfGG0i,iGG0f:;;;;:1C0f... .,:,:;:;i;,.::fC000Li,,,;;;;;;::,,,\n";
        std::cout << "1;;::;;;::,:ii;::::,..,1;,;iffLLi:::LGGLLfLG;:GCGL:;;;:iLGGL:....,::;;;::::.:LC0GLi;,....,:::,,....,\n";
        std::cout << "1::,,:,::::iii;::::,,..,i:,i:,t1,ii:f0CLCLfG;fCLC:,;;:1G00f, .....:;;;1;;,,:fCLt,...................\n";
        std::cout << "1::::::::::1iii;;;::,,,..:,:i:;i::;,::::10G1iCC0f1LLffG0G;.........;i;i1,.:fL;  ,:it:.iLt: .........\n";
        std::cout << "i;::::::::;iLC0Cfti;:,,,,...:i;;;;;.;111i81.,,i;t@0fCG0f,..:i;..,,,,:;it:.tL::1fLLLGG:i880t.........\n";
        std::cout << ":::::;;;:;;iC88888Gt::,,...,,:;;;;;,itti,i:i1f:;t;.iCGt...1L1;,,:::,.:i11.1;iGCCCCCC0f,0000;.,;.....\n";
        std::cout << "::::::::::;;1C88880L;::,,...:,,;;;:.,,,,.,;iii:1;;1i:;...1Cti;::::::,.;1tt::;fCLLCCLGti000G1.:L1....\n";
        std::cout << ":;;,,,,,:,::;1LGG0GGCt:,...,,::,::...:,,,.;Ci.:,,;111;,.:C111;;;i1i;:,.1fff,:;LLfLLLLttGGGf:;fCGL:..\n";
        std::cout << ";;:..,,,.,,,:,;ii1fCCLCC;,,,..,,..,,,1,:,.;i,. ;C:.,i:..,f11fLCCCGti;:,,ffL1,:;ffLLfL1fGCt,1LLfff1:,\n";
        std::cout << ";;i......,,,,,:ti:::::1i,;;... ...i:,;,;.:C;.,.:L: :;,..::GGGCfft1tt1i;;,tLt,,,tffft1it1;.:1iiitttf1\n";
        std::cout << ";;;,..,.,,,,...::,,,,,.. .,......,:.:::,.f1..,it;,it;11.::i1ii1tLCCf1i;i1:iLi,,:itti,,,,,:::;itftf1,\n";
        std::cout << "::;:.,,.,,,.,,:..:,:L,fGi,......,:,.:t:.it,..1Lt;111i;:,1ttt1tC08@@@8Cftf;,:t;,..::......:i1fG8808G:\n";
        std::cout << "::;;.,,...:1i...:t.L@;G0C0,.....:i:,,;,,11::fLtiiii:,,.:Lttt1tfLfLLLG08@88C.,i..f, ..,i11itfLCG0GGG1\n";
        std::cout << "::::,,,itG8f ;000: L@Lt8it;.....,ii,;;:;;:,:1iiiii,....:111ttfLLLfffttfLC8i  ;L8@:.,,iLfLt11fLG00GGC\n";
        std::cout << ":;;:. ,f8@0:.,C@8G..8G,@1 ,.   .::,,;;;1;;;:,....     ,;itti1fffLLLffLCCft;fG0Gft,,::1ftfftt1fL000GC\n";
        std::cout << "::::,. ,0@1 . .88@f Lt fG..,i,;i, ..,;iitfLLLLfLLCGGGGLi11t11fffffffffLCG00Ci,...,,,:tf1tfffttfCG0GL\n";
        std::cout << ":::::,,;@L.,,. f@8@;:;..:,;0800tfL00000CGCLfft11i;ii;i: ..,;tfttt;1tCG0GCf:.....,,,,ift11tfLti;tCG0C\n";
        std::cout << ".....,.t@; ,,...f@88,,:,.i@@@8LGGLttiii;;i;:.    .,,. ...,,,:;iG8CG0Cfffti::,....,.;ft11i1tLL1::tLCG\n";
        std::cout << ".......GG   ..,:,L@8C,,:,;Lti,    .,:;iiii:,,...,,,::,,...,,,.0@@0f1tfLf1;:,.....,.,;i111iitf1:,,;1t\n";
        std::cout << "..... :@1 ....,,.:88@C.,,,,. .,,:;ii111ii;,........,1i:,...,.1@Gt1ffLLti;:,,.....,,..,,;;;;;i11ttt1:\n";
        std::cout << "..... C@,..,,:;;;i1C@@G:.......,,,,,,,.......,,,:::1tt1i;:,,.1t:;tfft11i;:,,... .,,......,;1tttCCGGC\n";
        std::cout << "....,L88,.,.,.,:::,.;0@L .....   ....,::;i;;,:ttttffttfffti:,. ,:;;;;:;::,,..   ......,...,:;fiiffLC\n";
        std::cout << "... t@8G.....:,:i11t:tf:.  ........,,:;;i1i:,.:1ffffffLLLLfi;:. ..,,,.....       .........,,.1ttttfL\n";
        std::cout << "... .L@@:.:;:i1i1f1t:iti;1,....   ...,,,,:;i;;, tLffLLLfftt1i;..     .         .............:ttt1tLL\n";
        std::cout << ".... .LL:.,,:.,...,:iii1;::1..  ,,.....,,;iii;:.,fLfftt1111i:,..               ......  ...;111iittfL\n";
        std::cout << ".....    .     ,ifCGGGGCCt,.... ;;,,............ :Lfft11i;;:...                   ...:;:;i1iiii1ttfL\n";
        std::cout << ".... ....   .:1ffLLCCCLftLt,... ,i.....,,,.,,,:,,.itii;;:,..                     ..,,;;:;i;iii1ttffL\n";
        std::cout << "....      .,;1t11tfLLLft1;:,... .:.....,,,,,,:::,.......                         .....,::,:iiii1111i\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
    }

    if (!CDGame.IsGameWon())
    {
            std::cout << "OHH NYOOOO!!! \n";
            // Any technology to add more contrast like here?
           // std::cout << " ⣿⣿⣿⣿⣿⣿⡷⣯⢿⣿⣷⣻⢯⣿⡽⣻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠸⣿⣿⣆⠹⣿⣿⢾⣟⣯⣿⣿⣿⣿⣿⣿⣽⣻⣿⣿⣿⣿ \n";
          //  std::cout << " ⣿⣿⣿⣿⣿⣿⣻⣽⡿⣿⣎⠙⣿⣞⣷⡌⢻⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⡄⠹⣿⣿⡆⠻⣿⣟⣯⡿⣽⡿⣿⣿⣿⣿⣽⡷⣯⣿⣿⣿ \n";
          //  std::cout << " ⣿⣿⣿⣿⣿⣿⣟⣷⣿⣿⣿⡀⠹⣟⣾⣟⣆⠹⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢠⡘⣿⣿⡄⠉⢿⣿⣽⡷⣿⣻⣿⣿⣿⣿⡝⣷⣯⢿⣿ \n";
          //  std::cout << " ⣿⣿⣿⣿⣿⣿⣯⢿⣾⢿⣿⡄⢄⠘⢿⣞⡿⣧⡈⢷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣧⠘⣿⣷⠈⣦⠙⢿⣽⣷⣻⣽⣿⣿⣿⣿⣌⢿⣯⢿ \n";
          //  std::cout << " ⣿⣿⣿⣿⣿⣿⣟⣯⣿⢿⣿⡆⢸⡷⡈⢻⡽⣷⡷⡄⠻⣽⣿⣿⡿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣏⢰⣯⢷⠈⣿⡆⢹⢷⡌⠻⡾⢋⣱⣯⣿⣿⣿⣿⡆⢻⡿  \n";
          //  std::cout << " ⣿⣿⣿⣿⣿⣿⡎⣿⢾⡿⣿⡆⢸⣽⢻⣄⠹⣷⣟⣿⣄⠹⣟⣿⣿⣟⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⢸⣯⣟⣧⠘⣷⠈⡯⠛⢀⡐⢾⣟⣷⣻⣿⣿⣿⡿⡌⢿  \n";
          //  std::cout << " ⣿⣿⣿⣿⣿⣿⣧⢸⡿⣟⣿⡇⢸⣯⣟⣮⢧⡈⢿⣞⡿⣦⠘⠏⣹⣿⣽⢿⣿⣿⣿⣿⣯⣿⣿⣿⡇⢸⣿⣿⣾⡆⠹⢀⣠⣾⣟⣷⡈⢿⣞⣯⢿⣿⣿⣿⢷⠘  \n";
         //   std::cout << " ⣿⣿⣿⣿⣿⣿⣿⡈⣿⢿⣽⡇⠘⠛⠛⠛⠓⠓⠈⠛⠛⠟⠇⢀⢿⣻⣿⣯⢿⣿⣿⣿⣷⢿⣿⣿⠁⣾⣿⣿⣿⣧⡄⠇⣹⣿⣾⣯⣿⡄⠻⣽⣯⢿⣻⣿⣿⡇  \n";
        //    std::cout << " ⣿⣿⣿⣿⣿⣿⣿⡇⢹⣿⡽⡇⢸⣿⣿⣿⣿⣿⣞⣆⠰⣶⣶⡄⢀⢻⡿⣯⣿⡽⣿⣿⣿⢯⣟⡿⢀⣿⣿⣿⣿⣿⣧⠐⣸⣿⣿⣷⣿⣿⣆⠹⣯⣿⣻⣿⣿⣿  \n";
        //    std::cout << " ⣿⣿⣿⣿⣿⣿⣿⣿⠘⣯⡿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣧⡈⢿⣳⠘⡄⠻⣿⢾⣽⣟⡿⣿⢯⣿⡇⢸⣿⣿⣿⣿⣿⣿⡀⢾⣿⣿⣿⣿⣿⣿⣆⠹⣾⣷⣻⣿⡿  \n";
         //   std::cout << " ⣿⣿⣿⣿⣿⣿⣿⣿⡇⢹⣿⠇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠻⡇⢹⣆⠹⣟⣾⣽⣻⣟⣿⣽⠁⣾⣿⣿⣿⣿⣿⣿⣇⣿⣿⠿⠛⠛⠉⠙⠋⢀⠁⢘⣯⣿⣿  \n";
        //    std::cout << " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⡈⣿⡃⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡙⠌⣿⣆⠘⣿⣞⡿⣞⡿⡞⢠⣿⣿⣿⣿⣿⡿⠛⠉⠁⢀⣀⣠⣤⣤⣶⣶⣶⡆⢻⣽⣞⡿  \n";
        //    std::cout << " ⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠘⠁⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠛⢿⣄⢻⣿⣧⠘⢯⣟⡿⣽⠁⣾⣿⣿⣿⣿⣿⡃⢀⢀⠘⠛⠿⢿⣻⣟⣯⣽⣻⣵⡀⢿⣯⣟  \n";
       //     std::cout << " ⣿⣿⣿⣟⣿⣿⣿⣿⣶⣶⡆⢀⣿⣾⣿⣾⣷⣿⣶⠿⠚⠉⢀⢀⣤⣿⣷⣿⣿⣷⡈⢿⣻⢃⣼⣿⣿⣿⣿⣻⣿⣿⣿⡶⣦⣤⣄⣀⡀⠉⠛⠛⠷⣯⣳⠈⣾⡽  \n";
        //    std::cout << " ⣿⢿⣿⣿⣻⣿⣿⣿⣿⣿⡿⠐⣿⣿⣿⣿⠿⠋⠁⢀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣌⣥⣾⡿⣿⣿⣷！⣿⣿⢿⣷⣿⣿⣟⣾⣽⣳⢯⣟⣶⣦⣤⡾⣟⣦⠘⣿  \n";
       //     std::cout << " ⣿⣻⣿⣿⡷⣿⣿⣿⣿⣿⡗⣦⠸⡿⠋⠁⢀⢀⣠⣴⢿⣿⣽⣻⢽⣾⣟⣷⣿⣟⣿⣿⣿⣳⠿⣵⣧⣼⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣽⣳⣯⣿⣿⣿⣽⢀⢷  \n";
        //    std::cout << " ⣿⢷⣻⣿⣿⣷⣻⣿⣿⣿⡷⠛⣁⢀⣀⣤⣶⣿⣛⡿⣿⣮⣽⡻⣿⣮⣽⣻⢯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⢀⢸  \n";
        //    std::cout << " ⠸⣟⣯⣿⣿⣷⢿⣽⣿⣿⣷⣿⣷⣆⠹⣿⣶⣯⠿⣿⣶⣟⣻⢿⣷⣽⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢀⣯  \n";
       //     std::cout << " ⣇⠹⣟⣾⣻⣿⣿⢾⡽⣿⣿⣿⣿⣿⣆⢹⣶⣿⣻⣷⣯⣟⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢀⡿  \n";
       //     std::cout << " ⣿⣆⠹⣷⡻⣽⣿⣯⢿⣽⣻⣿⣿⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⢸⣿  \n";
       //     std::cout << " ⡙⠾⣆⠹⣿⣦⠛⣿⢯⣷⢿⡽⣿⣿⣿⣿⣆⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠎⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⢀⣿⣾  \n";
       //     std::cout << " ⣿⣷⡌⢦⠙⣿⣿⣌⠻⣽⢯⣿⣽⣻⣿⣿⣿⣧⠩⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⢰⢣⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⢀⢀⢿⣞  \n";
       //     std::cout << " ⣿⣽⣆⠹⣧⠘⣿⣿⡷⣌⠙⢷⣯⡷⣟⣿⣿⣿⣷⡀⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣈⠃⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢀⣴⡧⢀⠸⣿  \n";
      //      std::cout << " ⢻⣽⣿⡄⢻⣷⡈⢿⣿⣿⢧⢀⠙⢿⣻⡾⣽⣻⣿⣿⣄⠌⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⢁⣰⣾⣟⡿⢀⡄⢿  \n";
      //      std::cout << " ⡄⢿⣿⣷⢀⠹⣟⣆⠻⣿⣿⣆⢀⣀⠉⠻⣿⡽⣯⣿⣿⣷⣈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⢀⣠⠘⣯⣷⣿⡟⢀⢆⠸  \n";
       //     std::cout << " ⣷⡈⢿⣿⣇⢱⡘⢿⣷⣬⣙⠿⣧⠘⣆⢀⠈⠻⣷⣟⣾⢿⣿⣆⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⣠⡞⢡⣿⢀⣿⣿⣿⠇⡄⢸⡄  \n";
      //      std::cout << " ⣿⣷⡈⢿⣿⡆⢣⡀⠙⢾⣟⣿⣿⣷⡈⠂⠘⣦⡈⠿⣯⣿⢾⣿⣆⠙⠻⠿⠿⠿⠿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢋⣠⣾⡟⢠⣿⣿⢀⣿⣿⡟⢠⣿⢈⣧  \n";
      //      std::cout << " ⣿⣿⣿⣄⠻⣿⡄⢳⡄⢆⡙⠾⣽⣿⣿⣆⡀⢹⡷⣄⠙⢿⣿⡾⣿⣆⢀⡀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⢀⣀⣠⣴⡿⣯⠏⣠⣿⣿⡏⢸⣿⡿⢁⣿⣿⢀⣿  \n";
      //      std::cout << " ⣿⣿⣿⣿⣦⡙⣿⣆⢻⡌⢿⣶⢤⣉⣙⣿⣷⡀⠙⠽⠷⠄⠹⣿⣟⣿⣆⢙⣋⣤⣤⣤⣄⣀⢀⢀⢀⢀⣾⣿⣟⡷⣯⡿⢃⣼⣿⣿⣿⠇⣼⡟⣡⣿⣿⣿⢀⡿  \n";
      //      std::cout << " ⣿⣿⣿⣿⣿⣷⣮⣿⣿⣿⡌⠁⢤⣤⣤⣤⣬⣭⣴⣶⣶⣶⣆⠈⢻⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿⣷⣶⣤⣌⣉⡘⠛⠻⠶⣿⣿⣿⣿⡟⣰⣫⣴⣿⣿⣿⣿⠄⣷﻿  \n";

                std::cout << " \n";
                std::cout << "  .     .       . . . . . . . . . . . . . . . . . . . . . . . . . . . .     .     . . . . . . . .   . . . . . . . . . . .  \n";
                std::cout << "  .     .         . . . . . . . . . . . . . . . . . . . . . . . . . . .       .     . . . . . . .     . . . . . . . . . .  \n";
                std::cout << "        .         . . . . . . . . . . . . . . . . . . . . . . . . . . . .     .     . . . . . . .     . . . . . . . . . .  \n";
                std::cout << "      . . .       . . . . . . . . . . . . . . . . . . . . . . . . . . . .     . .   . . . . . . . .     . . . . . . . . .  \n";
                std::cout << "      . . .       . . . . . . . . . . . . . . . . . . . . . .     . . . .       .     . . . . . . .     . . . . . . . . .  \n";
                std::cout << "      . . .       . . . . . . . . . . . . . . . . . . . . . . .     . . . .     . .     . . . . . .     . . . . . . . . . \n";
                std::cout << "  .     . .   .             . . . . . . . . . . . . . . . . . .     . . . .     . .                       . . . . . . . . \n";
                std::cout << "        . .         . . . . . . . . . . . . . . . . . . . . . .       . . . .     . .                     . . . . . . . .  \n";
                std::cout << "        . .         . . . . . . . . . . . . . . . . . . . . . .       . .         . . . . . . . . . . .     . . . . . . .  \n";
                std::cout << "        .             . . . . . . . . . . . . . . . . . . . .                   . . . . . . . . . . . .     . . . . . . .  \n";
                std::cout << "  .     .   . .       . . . . . . . . . . . . . . . . . . .         .     . . . . . . . . . . . . . . .     . . . . . . .  \n";
                std::cout << "          . .     .   . . . . . . . . . . . . . . . .             . . . . . . . . . . . .             .     . . . . . . .  \n";
                std::cout << "          . .           . . . . . . . . . . . .           . . . . . . . . . . . . . .               . . .     . . . .   .  \n";
                std::cout << "          . . .     .   . . . . . . . . .           . . . . . . . . . . . . . . .         . . . . . . . .     . . . .   .  \n";
                std::cout << "  .   .   . . .     .     . . . . . .         . . . . . . . . . . . . . .   . .       . . . . . . . . . . .   . . . .   .  \n";
                std::cout << "      .     . . .     .     . . .       . . . . . . . . . . . . . . . . . . .     . . . . . . . . . . . . .   . . .     .  \n";
                std::cout << "            . . .     .             . . . . . . . . . . . . . . . . . . . .     . . . . . . . . . . . . . .   . . .     .  \n";
                std::cout << "        .   . . .     . .         . . . . . . . . . . . . . . . . . . . . .     . . . . . . . . . . . . . .   . . .     .  \n";
                std::cout << "  .     .   . . . .     .   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     . .     .  \n";
                std::cout << "        .     . .       . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     . .     .  \n";
                std::cout << "  .     . .   .       . . . . . . .     . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     . .     .  \n";
                std::cout << "  . .     .       . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     . .     .  \n";
                std::cout << "  . .       .   . . . . . .                 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .     . .        \n";
                std::cout << "    . .     . . . . .                 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .   .          \n";
                std::cout << "       .     . . .         . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .   .          \n";
                std::cout << "              . . .     . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .   .          \n";
                std::cout << "      .   .     . . . . . . . . . . . . . . . . . . . . . . . . . .               . . . . . . . . . . . . .       .   .    \n";
                std::cout << "  .   . .         . . . . . . . . . . . . . . . . . . . . . . .                     . . . . . . . . . . . .                \n";
                std::cout << "  .     . .         . . . . . . . . . . . . . . . . . . .                       .     . . . . . . . . .                    \n";
                std::cout << "  . .   . . .       . . . . . . . . . . . . . . . . . .               . . . . . . .   . . . . . . . .                      \n";
                std::cout << "  . .     . .         . . . . . . . . . . . . . . . .           . . . . . . . . . .   . . . . . . .       .   .   .   .    \n";
                std::cout << "  . . .   . . .       . . . . . . . . . . . . . . . . .     . . . . . . . . . . . .   . . . . . .                          \n";
                std::cout << "  . . .     . . .     . . . . . . . . . . . . . . . . .     . . . . . . . . . . . .   . . . . . .                         \n";
                std::cout << "  . . . .   . . .     . . . . . . . . . . . . . . . . .     . . . . . . . . . . . . . . . . .                              \n";
                std::cout << "  . . . .     . .       . . . . . . . . . . . . . . . . .   . . . . . . . . . . . . . . . .       .   .   .   .   .       \n";
                std::cout << "  . . . . .   . . .     . . . . . . . . . . . . . . . . .     . . . . . . . . . . . . .                           .     .  \n";
                std::cout << "  . . . . .     . .       . . . . . . . . . . . . . . . . .     . . . . . . . . . .                       . .     . . . . \n";
                std::cout << "  . . . . . .     . .       . . . . . . . . . . . . . . . . . . . . . . . . . .       . .                   . .     . . . \n";
                std::cout << "  . . . . . .     . .               . . . . . . . . . . . . . . . . . .           . . . . .   .       .     . . .   . . .  \n";
                std::cout << "  . . . . . . .     . .                                                   . . . . . . . . . .       . . .     . .   . . . \n";
    }
}
