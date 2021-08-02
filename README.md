
# push_swap


https://discord.com/channels/774300457157918772/817041043764805692/850354416813080576

https://discord.com/channels/774300457157918772/817041043764805692/819531131870642197

**to do**
nb negatif ????
- main : find from argv
- output ?
- gérer les str MAIS AUSSI LES INT
- gérer les erreurs si ce n'est pas un chiffre
- ARG="" && make push_swap  && ./push_swap $ARG SEGFAULT

**done**
- entier positif et négatif
- build_stack_b???
- uniformiser les pointeurs (pas de return)

**documentation**
- reminder on pointer and why to use double pointer for a linked list : https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/

**compil**
ARG="5 1 3 4 2" && make push_swap  && ./push_swap $ARG | ./checker_Mac $ARG

ARG="1" && make push_swap  && ./push_swap $ARG | ./checker_Mac $ARG
ARG="1" && make push_swap  && ./push_swap $ARG


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




ARG="379 967 563 242 384 716 915 436 83 263 93 311 45 778 943 533 424 894 724 684 48 374 676 862 120 241 564 148 702 990 293 816 983 470 795 487 833 383 329 902 306 851 166 781 57 127 447 793 446 430 109 546 505 941 443 699 826 884 89 886 503 739 984 718 313 468 701 661 113 325 754 60 287 600 176 139 714 348 71 59 448 744 230 561 951 979 418 532 107 198 292 300 415 246 611 843 692 657 777 423 991 613 594 766 973 359 794 186 955 151 726 334 484 565 615 422 571 544 189 748 982 601 535 922 694 369 559 321 507 800 352 294 974 137 274 185 551 357 669 265 163 178 560 547 100 956 606 880 927 948 164 664 467 368 343 923 952 715 874 290 301 395 756 251 156 757 903 49 367 878 143 867 190 483 940 478 317 887 667 772 652 199 316 258 513 131 474 134 180 228 494 433 399 645 201 745 318 147 249 763 907 897 909 402 476 989 609 917 847 428 75 439 818 259 254 140 269 477 170 222 349 538 969 591 209 489 980 767 150 604 610 214 696 747 838 944 972 220 643 172 935 286 861 671 346 542 427 650 225 537 850 297 586 783 589 994 780 549 534 579 326 659 957 509 308 987 298 145 574 921 353 729 270 855 898 417 194 175 277 377 410 479 449 837 425 267 801 165 182 240 674 264 299 403 852 708 786 857 146 328 788 958 303 592 118 939 171 598 992 177 389 406 623 577 768 356 233 327 912 340 516 597 531 946 853 709 966 211 541 552 572 653 828 271 360 215 981 501 820 576 314 455 742 257 281 105 272 472 588 841 520 892 115 758 770 440 977 870 461 743 648 239 291 284 860 279 854 868 913 363 720 124 662 19 675 697 370 412 799 132 394 103 227 262 807 466 890 844 680 119 840 475 387 116 456 954 835 761 460 232 207 420 167 536 873 408 727 481 244 683 640 693 495 617 904 401 649 773 931 213 519 160 413 805 670 498 668 769 490 236 226 373 304 255 154 463 179 347 965 735 959 651 391 555 337 155 911 191 945 502 728 918 687 521 581 810 121 920 803 338 765 111 496 901 437 333 554 144 621 512 908 339 686 248 685 963 690 771 628 452 161 616 784 962 655 644 192 797 575 110 221 731 831 469 126 587 123 130 725 602" && make push_swap  && ./push_swap $ARG









