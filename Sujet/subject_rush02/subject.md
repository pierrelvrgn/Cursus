
# RUSH 02
# --^^_The P^N Championship_^^--

## _Parce que vous vous pensiez capables de coder une IA d'échec ? En Deux Jours ?_

![Mhouppin is laughing at you !](https://cdn.intra.42.fr/users/medium_mhouppin.jpg)

-------------------

### Description et Regles basiques

> _Puissance 4 (appelé aussi parfois 4 en ligne) est un jeu de stratégie combinatoire abstrait,   
> commercialisé pour la première fois en 1974 par la Milton Bradley Company,    
> plus connue sous le nom de MB et détenue depuis 1984 par la société Hasbro._   
>
> _Le but du jeu est d'aligner une suite de 4 pions de même couleur sur une grille comptant 6 rangées et 7 colonnes.   
> Chaque joueur dispose de 21 pions d'une couleur (par convention, en général jaune ou rouge).   
> Tour à tour, les deux joueurs placent un pion dans la colonne de leur choix,   
> le pion coulisse alors jusqu'à la position la plus basse possible dans la dite colonne   
> à la suite de quoi c'est à l'adversaire de jouer.  
> Le vainqueur est le joueur qui réalise le premier un alignement (horizontal, vertical ou diagonal) consécutif   
> d'au moins quatre pions de sa couleur. Si, alors que toutes les cases de la grille de jeu sont remplies,   
> aucun des deux joueurs n'a réalisé un tel alignement, la partie est déclarée nulle._
> 
>> https://fr.wikipedia.org/wiki/Puissance_4

-----------------

## Votre boulot

### Un abruti averti vaut mieux que deux ignares

Votre mission, si vous l'acceptez, est de mettre au point un **algorithme** capable de jouer au _Puissance N_.

Votre programme a pour objectif de gagner chaque duel, dans le **temps imparti** donné par l'arbitre ou _referee_.

Votre programme a pour premier objectif de gagner le ***championnat du monde de P^N***, se deroulant ici-meme,   
a 42 Lyon - Auvergne Rhone-Alpes.
> _How ! Quelle chance !_

Le ***championnat du monde de P^N*** se déroulera la semaine suivant le rush.

Votre code sera copié dimanche soir à la fin du Rush.

### Fonctionnement et déroulement

Le ***Puissance N*** ou ***Connect N*** est pensé comme un dérivé du ***Puissance 4*** ou ***Connect 4*** :
- La taille du plateau (_width/height_) est variable,
- Le nombre de pions nécéssaire à la victoire (_connect number_) sera compris entre 3 et 5,
- Vous passerez par un arbitre pour chacun de vos coups

Cette version est un **Combat a mort** : _Il y aura toujours un vainqueur_. Autres conditions de victoire :
- Le joueur adverse triche (victoire par forfait),
- Le joueur adverse ne peut plus poser de piece,
- Le joueur adverse n'a plus de temps.

Le _referee_ vous donnera les informations necessaires au déroulement de la partie.   
Il lira sur votre `stdin` et ecrira sur votre `stdout`.   
> Pour en savoir plus sur son fonctionnement, consulter le `PROTOCOL.md`.

Pour **jouer un coup**, vous devrez écrire sur `stdin` et lire sur `stdout`, alors captures.   
Le coup, qui se dit _move_ en Anglais d'Angleterre, des Etats-Unis d'Amerique, d'Afrique du Sud, d'Inde ou   
de n'importe quel autre pays ou region ou se parle cette langue (c'est-a-dire presque partout maintenant),    
sera un `int` unique précisant **la colonne** où votre IA (ou quoi que ce soit) doit jouer.

### Nos petits cadeaux : _REFEREE & AI_

Nous vous avons fourni **trois IA** sous forme d'exécutables.   
Trois niveaux de difficulte ont ete prevus comme _punching ball_ : __easy__, __medium__, __hard__.

Pour vous éviter de devoir recoder un arbitre, nous vous avons donne un binaire dans le but de le remplacer.
Bien qu'il ne soit qu'une pâle copie de son homologue ***[Pierluigi Collina](https://www.youtube.com/watch?v=O6JQTmvAgyU)***,
il vous permettra de tester manuellement les Bots et automatiquement quand vous aurez trouve le moyen  
de faire marcher votre usine a gaz.

Son fonctionnement est detaillé au sein du `PROTOCOL.md` (`./REFEREE_macos/`) dans un très bel anglais, celui de Sir DoomDuck (_dburgun_).

> _Les Bots n'ont pour seul dessein que de servir d'entrainement. Ils ne seront pas utilisés dans le championnat._

> _Le Referee est un arbitre fiable. Les duels fonctionneront exactement de la même façon (déroulement, contraintes...)   
> pendant le championnat._

--------------------------

## Un max de personnalisation ! Utilisez le débardeur !

Afin qu'il n'y ait aucun _probleme de compatibilité_ avec notre environnement, il est nécéssaire que vous créiez   
et testiez le votre.

Pour cela, vous devrez _confectionner_, _personnaliser_ et _optimiser_ votre ***Dockerfile***.   

> _Le Grand Sage Monsieur Mhouppin a dit un jour : le build fait partie de l'étape d'optimisation. Le meilleur des      
> algorithme ne pourra pas combler les déficits d'une mauvaise librairie ou un temps de run trop long._

L'optimisation passe aussi par un environement de test léger, fiable, parfaitement configuré.   

Pour vous aider dans votre quête, nous vous avons laissé des **blueprints**, des `Dockerfiles` documentés dont un `Dockerfile_example` (./dock/) qui   
parlera aux plus fideles adeptes du C.

> _Nous vous recommandons fortement de lire les deux Dockerfiles fournis, que vous soyez experts ou neophytes du sujet.   
> Ils sont annotés, et ces annotations sont capitales pour rendre un Dockerfile valide._

### Consignes

Votre Dockerfile doit être a la racine du _repository_.

Votre Dockerfile doit lancer votre IA lorsque l'on `run` le container.

Votre IA doit etre capable de fonctionner normalement une fois le container devenu actif.

Vous devez posséder, utiliser et respecter les lignes annotés `Mandatory` dans votre Dockerfile.

Vous êtes libres de proposer votre Dockerfile, mais vous devez garder les lignes `Mandatory` présentes et fonctionnelles.

> _Le temps de build n'est pas compté dans le temps de jeu, mais *un build trop long* pourrait etre ***stoppé***, entrainant la   
> défaite de l'équipe._

Restez le plus simple possible.

### Conseils

Il y a un bon million de **bonnes pratiques** pour faire un Dockerfile, mais comme le votre doit rester simple et efficace,  
nous nous cantonerons aux éléments les plus basiques :
- Utilisez le **moins de commande** `RUN` possible.
- Le `multi-stage build` permet de ne garder que le nécessaire dans le container.
- La commande `CMD` est sensible : si la commande lancee par son biais se met en sommeil ou s'arrete, votre container s'arrete   
et redémarrera (selon vos parametres).
- Utilisez une **image toute faite** de préférence. Il existe tout un tas d'images officielles propres a un langage en particulier,  
par exemple le [Go](https://hub.docker.com/_/golang/) sur le [hub docker](https://hub.docker.com/).
- Au lieu de faire des milliers de builds pour tester votre Dockerfile, préférez toujours la ***configuration manuelle*** ;  
pour cela, faites un `build` presque vierge d'une image, obtenez l'accès a un bash, et faites vos commandes mauellement.   
Sauvegardez ensuite les commandes fonctionnelles dans votre Dockerfile.
- N'oubliez pas de kill les containers inutiles et d'effacer les images docker ou votre systeme en patira.

### Commandes

Voici les commandes qui peuvent-être utilisées :   

`docker build -d .` -> build le container depuis une image.

`docker exec -ti [container name] /bin/bash` -> obtenir l'accès a un terminal dans un container.

`docker ps` -> lister les containers en fonctionnement.

`docker images` -> lister les images docker.

`docker kill [container name]` -> kill un container en fonctionnement.

`docker rmi [image]` -> supprimer une image. 



--------------------
--------------------

#### N'oubliez pas que le but d'un Rush est d'apprendre, de tester ses competence et de passer un bon moment.
#### Privilegiez toujours l'entraide, notammment pour la partie Dockerfile.



> _Voilà la seule ressource nécessaire pour commencer : https://en.wikipedia.org/wiki/Minimax
