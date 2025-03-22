# Projet en cours ♻️
- Trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles.
- Manipuler différents algorithmes de tri et choisir la (ou les ?) solution la plus appropriée pour un classement optimisé des données. 
- Page 15/15 done

### Keywords
- Notion de pile et éléments de manipulation
- Complexite (le + vite possible)

## To code
- [ ] parsing arguments propre
- [ ] En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur. Si certains paramètres ne sont pas des nombres, ne tiennent pas dans un int, ou encore, s’il y a des doublons
- [ ] avec "", sans, variable
- [ ] structure : **liste chainee** circulaire ou tableau (index ?) ou liste doublement chainee
- [ ] actions (why code instructions ?)
- [ ] Implementer l'algorithme de tri (turc, radix)
- [ ] 1 ens/liste d'entiers (?) donc pas de doublon (+ou-) -> logiciel, cmb ? 
- [ ] creer 2 piles (pile a: 1 **liste**/pile/ens (?) **d'entiers** et b: vide) -> attention a l'ordre 
- [ ] 1 ens limite d'instructions pour manipuler les piles: 
- [ ] 1 programme qui prend en parametre la pile a (premier parametre au sommet de la pile), calcule et affiche sur la sortie standard le + petit programme, fait d'instructions du langage push swap permettant de trier les entiers passes en parametres par ordre croissant, plus petit en premier (au sommet de la pile)
- [ ] separer par only '\n' instructions
- [ ] read ?
- [ ] write ? -> ft_printf
- [ ] malloc, free ?
- [ ] exit ?
- [ ] bon affichage \n
- [ ] normalize the list/your data -> radix sort 

## To test
- [ ] 80% : trier 100 nombres aléatoires en moins de 700 opérations (moyenne, mais vous devriez toujours avoir au max moins de 700 opérations pour effectuer le tri complet) -> cas ou tri plus long ?
- [ ] 100% : trier 500 nombres aléatoires en un maximum de 5500 opérations
- [ ] norminette
- [ ] executer commandes pour test vrmt trier -> checker 
- [ ] x segmentation fault x bus error x double free, ds cas limites definis 
- [ ] visualizer/franci/checker 
- [ ] make fclean, enlever checker -> file names/git repo
- [ ] (guidelines -> main/tests : 3 exemples subject)
- [ ] valgrind (no leaks)
- [ ] "your Makefile must not relink"
