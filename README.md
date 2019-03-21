# Parse_CSFML
Parse for CSFML

ENG :

Type:

G = Game object
M = Music
S = Sound
B = Boutton
T = Text
\# = Comment


Each argument is not required to be used there are default values ​​but for some argument is very recommendable. In addition, the argument has no order

Game Object:\n
    Path = "path": Retrieves the path of the texture in relation to the executable\n
    Type = nbr: Set the game object to this id which is useful for later retrieve it
    Rect = (x, y, width, height): Set the sprite rect
    Pos (x, y): Takes the sprite is the place at the coordinate attention it does it with respect to the middle of the rect of the sprite
    Prio = nbr: Knowing which layer will be displayed on the game object. 1 being the highest layer. Knowing the buttons and the game object uses the same system
    Disp = nbr: If Disp is equal to 0 it is not show or otherwise it is show


Boutton:
    Pos (x, y): Takes the Boutton is the place at the coordinate attention it does it with respect to the middle of the button without the outline
    Size = (width, height): Set the size of the button
    ID = nbr: Set the button to this id which is useful for later retrieve it
    Color = (r, b, g, a): Set the color of the button
    Color_Out = (r, b, g, a): Set the color of the button's outline
    Size_Out = nbr: Set the size of the outline
    Prio = nbr: Knowing which layer will be displayed on the game object. 1 being the highest layer. Knowing the buttons and the game object uses the same system
    Status = nbr: 1 = activate, 2 = deactivate, 3 = invisible, 4 = invisible + desactivate
    GO = nbr: Game object id that is bind to him
    Fc_hoex = function_name: Need to put a name in the file fc_for_button.h in the table fc_name and then in the table function place the function pointer in the same place as in the table fc_name and then set the button automatically when we are going to remove the mouse on him on it will launch the set fnction in the table
    Fc_ho = function_name: Need to put a name in the file fc_for_button.h in the table fc_name and then in the table function place the function pointer in the same place as in the table fc_name and then set the button automatically when we go the mouse on him on it will launch the set fnction in the table
    Fc_cl = function_name: Need to put a name in the file fc_for_button.h in the table fc_name and then in the table function place the function pointer in the same place as in the table fc_name and then set the button automatically when we click above it will launch the set fnction in the table

Sound:
    Path = "path": Recover the sound's path from the executable
    Vol = nbr: Set the volume of the sound
    Loop = nbr: If loop = 0 the sound will not loop or if loop = 1 the sound will loop
    ID = nbr: Set the sound to this id which is useful for later retrieve it

Music:
    Path = "path": Retrieves the path of music in relation to the executable
    Vol = nbr: Set the volume of the music
    Loop = nbr: If loop = 0 the music will not loop or if loop = 1 the music will loop
    ID = nbr: Set the music to this id which is useful for later retrieve it

Text:
    Pos (x, y): Take the text is the place at the coordinates
    ID = nbr: Set the Text to this id which is useful for later retrieving it
    Disp = nbr: If Disp is equal to 0 it is not show or otherwise it is show
    Sizechar = nbr: Set the size of the characters
    Str = "str": Set the text to the str
    
    
FR :

Type :

G = Game object
M = Music
S = Sound
B = Boutton
T = Text
\# = Commentaire


Chacun des argument n'est pas obliger d'etre utiliser il y a des valeur par defaut mais pour certain argument c'est tres recommander. De plus les argument n'a pas d'ordre

Game Object :
    Path="path" : Recupere le path de la texture par rapport a l'executable
    Type=nbr : Set le game object a cette id ce qui utile pour plus tard le recuperer
    Rect=(x,y,width,height) : Permet de set le rect du sprite
    Pos(x,y) : Prend le sprite est le place au coordonne attention il le fait par rapport au milieu du rect du sprite
    Prio=nbr : Savoir sur quelle couche va etre afficher le game object. 1 etant la couche la plus haute . Sachant les boutton et les game object utilise le meme systeme
    Disp=nbr : Si Disp est egale a 0 il est pas afficher ou sinon il est afficher


Boutton :
    Pos(x,y) : Prend le Boutton est le place au coordonne attention il le fait par rapport au milieu du boutton sans le contour
    Size=(width,height) : Permet de set la taille du boutton
    ID=nbr : Set le boutton a cette id ce qui utile pour plus tard le recuperer
    Color=(r,b,g,a) : Permet de set la couleur du boutton
    Color_Out=(r,b,g,a) : Permet de set la couleur du contour du boutton
    Size_Out=nbr : Permet de set la taille du contour
    Prio=nbr : Savoir sur quelle couche va etre afficher le game object. 1 etant la couche la plus haute . Sachant les boutton et les game object utilise le meme systeme
    Status=nbr : 1=activate, 2=desactivate, 3=invisible, 4=invisible+desactivate
    GO=nbr : Id du game object qui est lier a lui
    Fc_hoex=nom_de_function : Besoin de mettre un nom dans le fichier fc_for_button.h dans le tableau fc_name puis dans le tableau fonction placer le pointeur de fonction a la meme place que dans le tableau fc_name et puis va set automaticement le boutton que quand on va enlever la souris sur lui dessus il va lancer la fnction set dans le tableau
    Fc_ho=nom_de_function : Besoin de mettre un nom dans le fichier fc_for_button.h dans le tableau fc_name puis dans le tableau fonction placer le pointeur de fonction a la meme place que dans le tableau fc_name et puis va set automaticement le boutton que quand on va passer la souris sur lui dessus il va lancer la fnction set dans le tableau
    Fc_cl=nom_de_function : Besoin de mettre un nom dans le fichier fc_for_button.h dans le tableau fc_name puis dans le tableau fonction placer le pointeur de fonction a la meme place que dans le tableau fc_name et puis va set automaticement le boutton que quand on va cliquer dessus il va lancer la fnction set dans le tableau

Sound :
    Path="path" : Recupere le path du sound par rapport a l'executable
    Vol=nbr : Set le volume du sound
    Loop=nbr : Si loop = 0 le son ne va pas boucler or si loop = 1 le son va boucler
    ID=nbr : Set le son a cette id ce qui utile pour plus tard le recuperer

Music :
    Path="path" : Recupere le path de la musique par rapport a l'executable
    Vol=nbr : Set le volume de la musique
    Loop=nbr : Si loop = 0 la musique ne va pas boucler or si loop = 1 la musique va boucler
    ID=nbr : Set la musique a cette id ce qui utile pour plus tard le recuperer

Text :
    Pos(x,y) : Prend le text est le place au coordonne
    ID=nbr : Set le Text a cette id ce qui utile pour plus tard le recuperer
    Disp=nbr : Si Disp est egale a 0 il est pas afficher ou sinon il est afficher
    Sizechar=nbr : Set la taille des charactere
    Str="str" : Set le text a la str

