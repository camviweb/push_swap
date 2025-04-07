# Projet en cours ♻️

## Description 
- Trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles.
- Page 15/15 done

### Keywords
- Notions de pile et éléments de manipulation
- Complexité (le + vite possible)

### Algorithme de tri choisi 
- Tri turc car optimisé : on prend chaque élément de la pile a et on le place au bon endroit dans la pile b. Le tri radix semblait trop technique avec les bits (normaliser).

### Structure choisie pour la pile
- Liste chaînée plutôt que tableau avec buffer pour la scalabilité. Liste chaînée simple car pas vu utilité liste circulaire ou doublement chaînée. 

## To code
- [ ] 1 programme qui prend en parametre la pile a (premier parametre au sommet de la pile), calcule et affiche sur la sortie standard le + petit programme, fait d'instructions du langage push swap permettant de trier les entiers passes en parametres par ordre croissant, plus petit en premier (au sommet de la pile)
- [ ] separer par only '\n' instructions
- [ ] read ?

## To test
- [ ] 80% : trier 100 nombres aléatoires en moins de 700 opérations (moyenne, mais vous devriez toujours avoir au max moins de 700 opérations pour effectuer le tri complet) -> cas ou tri plus long ?
- [ ] 100% : trier 500 nombres aléatoires en un maximum de 5500 opérations
- [ ] norminette : structures dans un autre .h ?
- [ ] executer commandes pour test vrmt trier -> checker 
- [ ] x segmentation fault x bus error x double free, ds cas limites definis 
- [ ] franci/checker
- [ ] make fclean, enlever checker -> file names/git repo
- [ ] (guidelines -> main/tests : 3 exemples subject)
- [ ] valgrind (no leaks)
- [ ] "your Makefile must not relink"
- [ ] cas "1 2 " " 2 3" ./push_swap "1 2 4 3" 76 90 "348 05 -> choice
- [ ] cas 1 seul nb
- [ ] variable comme arg
