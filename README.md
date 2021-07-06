# push_swap


https://discord.com/channels/774300457157918772/817041043764805692/850354416813080576


**to do**
- main : find from argv
- output ?
- gérer les str MAIS AUSSI LES INT
- gérer les erreurs si ce n'est pas un chiffre


**done**
- entier positif et négatif
- build_stack_b???
- uniformiser les pointeurs (pas de return)

**documentation**
- reminder on pointer and why to use double pointer for a linked list : https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/

**compil**
ARG="4 67 3 87 23" && make push_swap  && ./push_swap $ARG | ./checker_Mac $ARG
make push_swap && ARG="4 67 3 87 23"   && ./push_swap $ARG | ./checker_Mac $ARG
make push_swap && ARG="0" ./push_swap $ARG | ./checker_Mac $ARG

ARG="4 67 3 87 23" && make push_swap  && ./push_swap $ARG
ARG="2 1 3 6 5 8" && make push_swap  && ./push_swap $ARG



ARG = "4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG = "4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

make checker ; ARG="4 67 3 87 23"; ./checker $ARG
make test ; ARG="4 67 3 87 23"; ./test $ARG
make test ; ./test $ARG


make cleaner && make push_swap && ARG="4 67 3 87 23" && ./push_swap $ARG && ./checker $ARG

**to do**
- makefile for automated testing
- try sort algo
- checker program : arg ?
- push swap program : arg ?

**bareme**

Pour 3 values = entre 2 / 3 opérations
Pour 5 values = max 12
Pour 100 values = barème de 1 à 5
  - moins de 700: 5
  - moins de 900: 4
  - moins de 1100: 3
  - moins de 1300: 2
  - moins de 1500: 1
Pour 500 values = barème de 1 à 5
  - moins de 5500: 5
  - moins de 7000: 4
  - moins de 8500: 3
  - moins de 10000: 2
  - moins de 11500: 1

**notes**

Mes conseils :
- commence par le checker (et sois sûr qu'il marche lol)
- pour push_swap: fais les cas les plus simples en premier (une stack de 2 à 3 chiffres)
- code un algo qui trie dans tous les cas avant de vouloir faire un truc opti (même si il est super lent)

Autres :
- les prototypes de brute force, insertion sort et quicksort

- je comprend pas comment recuperer mes $ARG quand je rentre dans mon programme ... Autant quand c'est avec **argv j'ai pas de soucis, mais quand c'est une variable je comprend pas ou c'est stocker et comment j'y accède dans le programme ?
je suis obligé de split car c'est un seul argument dans une string.

c'est le fonctionnement de zsh qui fait que tu vas avoir une seule string, teste avec bash et tu verras que ça fonctionne sans avoir besoin de passer par un split

- Autre que liste chainee :
https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
ben pa c'est pop b + push a. La fonction pop retourne la valeur que tu viens de poper, descend ou monte l'index de la stack qui a popé. Tu la récupère et la push dans a. Par exemple.
C'est une structure de donnée à créer et ses petites fonctions à créer

- C'est ok de demander au correcteur d'utiliser bash pour la correction plutot de zsh ?


- Pour être sûre de bien comprendre le sujet, dans le cas du checker programme, en reprenant l'exemple de la page 9, on le lance d'abord en faisant
./checker 3 2 1 0 Enter
puis le programme attend qu'on entre des instructions de la forme:
rra\npb\nsa\nrra\npa\n Enter
C'est bien ça?
cmorel-a (Céline) — 05/03/2021
sur l'entrée standard enter équivaut à \n
pour avoir ton EOF (\0), il va falloir faire un ctrl + d

- si jamais tu ne fais que tester ton checker tu peux lui envoyer un ctrl-d pour eof et lui faire comprendre qu'il n'y a plus d'instructions à exécuter mais à terme vu que checker prends l'output de pushswap il n'y en aura plus besoin étant donné qu'il ne fera que lire les instructions envoyées par pushswap jusque eof

- Tu passes avec un score de 86% et tu obtiens 12 jours de blackhole.

- les ternaires et les attributions de variable dans des conditions de if devaient être interdites (le fameux if (! a = malloc) par exemple)

- Vous devez écrire un programme nommécheckerqui prend en paramètre la pileasous
la forme d’une liste d’entiers. Le premier paramètre est au sommet de la
pile (attention donc à l’ordre).
•Checkerdoit ensuite attendre de lire
des instructions sur l’entrée standard, chaqueinstruction suivie par un ’\n’.
Une fois toutes les instructions lues, le checker vaexécuter ces instructions
sur la pile d’entiers passée en paramètres.
•Si après exécution la pileaest bien
triée et la pilebest vide, alorscheckerdoitafficher"OK"suivi par un ’\n’
sur la sortie standard. Dans tous les autres cas,checkerdoit afficher"KO"suivi
par un ’\n’ sur la sortie standard.
•En cas d’erreur, vous devez afficher
Errorsuivi d’un ’\n’ sur lasortie d’erreur.Par exemple si certains paramètres
ne sont pas des nombres, certains paramètresne tiennent pas dans unint,
s’il y a des doublons, ou bien sûr si une instructionn’existe pas ou est mal formatée.

**test to do**
- stack with "", "     ", "0    "

**pseudo code**
9 11 10
- Need :
head
current = head->next
prev = head
tmp
- first loop
9 < 11 (current < next>)
current = current->next
- second loop
11 > 10 (current > next):
  - while 10 >= prev
  - swap the value of 11 and 10 (so prev and current )







