# Libft - Projet École 42

Le projet Libft à l'École 42 vise à créer une bibliothèque de fonctions standard en langage C, ainsi que des fonctionnalités bonus, pour consolider les compétences de programmation en C. Cette bibliothèque devient une ressource essentielle pour les projets ultérieurs au sein de l'école.

<br>

## Description

La bibliothèque Libft propose une variété de fonctions standard en C, équivalentes à celles de la bibliothèque standard. Ces fonctions incluent la manipulation de chaînes de caractères, la gestion de la mémoire, les opérations sur les caractères, et bien plus encore. La conception de ces fonctions permet de comprendre en profondeur leur fonctionnement, renforçant ainsi les bases en programmation.

<br>

## Fonctions de Base

### 1. Chaînes de Caractères (`ft_str`)

Les fonctions de manipulation de chaînes de caractères incluent des opérations comme la copie, la concaténation, la recherche et la comparaison. Elles facilitent la gestion de chaînes de caractères en C.

- **ft_strlen** : Calcule la longueur d'une chaîne de caractères.
- **ft_strcpy** : Copie une chaîne dans une autre.
- **ft_strcat** : Concatène deux chaînes.
- **ft_strcmp** : Compare deux chaînes de caractères.
- ...

### 2. Mémoire (`ft_mem`)

Les fonctions de manipulation de la mémoire offrent des outils pour allouer et libérer la mémoire, ainsi que pour manipuler son contenu.

- **ft_memset** : Remplit une zone de mémoire avec une valeur spécifique.
- **ft_memcpy** : Copie une zone de mémoire d'une source à une destination.
- ...

### 3. Caractères (`ft_char`)

Les opérations sur les caractères comprennent la conversion entre majuscules et minuscules, la vérification de la catégorie d'un caractère, etc.

- **ft_isalpha** : Vérifie si un caractère est une lettre.
- **ft_isdigit** : Vérifie si un caractère est un chiffre.
- **ft_tolower** : Convertit une lettre en minuscule.
- ...

<br>

## Fonctionnalités Bonus

### 1. Listes Chaînées (`ft_lst`)

Les listes chaînées sont des structures de données dynamiques qui permettent de stocker et d'organiser des données de manière flexible. La bibliothèque Libft propose des fonctions pour manipuler ces structures.

- **ft_lstnew** : Crée un nouvel élément de liste.
- **ft_lstadd_front** : Ajoute un élément au début de la liste.
- **ft_lstsize** : Donne la taille de la liste.
- ...

### 2. ft_printf

La fonction ft_printf est une version personnalisée de la fonction printf en C, avec des spécificateurs de format étendus et la possibilité de modifier la couleur lors de l'affichage.

```c
ft_printf("%sNombre : %d, Chaîne : %s%s\n", CYAN, 42, "libft", COLOR_OFF);
```

Les couleurs disponibles sont : `BLACK`, `RED`, `GREEN`, `YELLOW`, `BLUE`, `PURPLE`, `CYAN`, `WHITE`, `COLOR_OFF`.

<br>

## Utilisation


### 1. Clonez le Dépôt :

```bash
git clone https://github.com/Wemubis/Libft.git
```

### 2. Compilation de la bibliothèque :

```bash
make
```

### 3. Exemples
Voici quelques exemples d'utilisation de la bibliothèque Libft :

```c
#include "libft.h"

int main() {
    // Utilisation de fonctions standard
    ft_putstr("Hello, World!\n");

    // Utilisation de fonctions bonus (listes chaînées)
    t_list *list = ft_lstnew("42");
    ft_lstadd_front(&list, ft_lstnew("Ecole"));

    // Utilisation de ft_printf avec couleur
    ft_printf("%sNombre : %d, Chaîne : %s%s\n", CYAN, 42, "libft", COLOR_OFF);

    return 0;
}
```