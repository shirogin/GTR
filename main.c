#include <stdio.h>
#include <stdlib.h>
#define Longueur_Max 300
#define Longueur_Max_Mot 50
#define Longueur_Max_T 255

/* 1- longueur de chain */
int Longueur(const char *text)
{
    int i = 0;
    while (text[i] != '\0' && i < Longueur_Max)
        i++;
    return i;
}
/* 2- nombre des mots dans une chaine de caract�re */
int NbrDesMots(const char *msg)
{
    int N = 0, l = Longueur(msg);
    if (l > 0 && !(msg[0] == ' ' || msg[0] == '\t'))
        N++;
    for (int i = 0; i < l; i++)
        if ((msg[i] == ' ' || msg[i] == '\t') && (i + 1 < l && !(msg[i + 1] == ' ' || msg[i + 1] == '\t')))
            N++;
    return N;
}
/* 3- Nombre des caractere numeric dans une chaine */
int NbrNum(const char *msg)
{
    int l = Longueur(msg), N = 0;
    for (int i = 0; i < l; i++)
        if (msg[i] >= 48 && msg[i] < 58)
            N++;
    return N;
}
/* 4- remplace un caract�re par un autre */
void RemplaceC(char *text, const char c1, const char c2)
{
    int l = Longueur(text), i = 0;
    while (i < l && text[i] != c1)
        i++;
    if (i < l)
        text[i] = c2;
}
/* 5- ins�re un mot � une position donn�e du texte */
void InsereUnMot(char *text, const char *mot, int position)
{
    int i, l = Longueur(text), m = Longueur(mot);
    if (position > l)
    {
        printf("position est plus grand que la taille de text");
        return;
    }
    if ((l + m) > Longueur_Max)
    {
        printf("La taille de text apr�s l'insertion es plus grand que %d", Longueur_Max);
        return;
    }
    for (i = l + m + 1; i > position + m - 1; i--)
    {
        text[i] = text[i - m];
    }
    for (i = position; i < position + m; i++)
    {
        text[i] = mot[i - position];
    }
}
/* 6- v�rifie l�existence d�un mot dans le texte */
int MotExist(const char *text, const char *mot)
{
    int exist = 0, i = 0, l = Longueur(text), m = Longueur(mot);
    while (exist == 0 && i < (l - m + 1))
    {
        if (text[i] == mot[0])
        {
            int j = 1;
            while ((i + j) < l && j < m && text[i + j] == mot[j])
                j++;
            if (j == m)
                exist++;
        }
        i++;
    }
    return exist;
}
/* 7- remplace un mot par un autre mot.*/
void RemplaceM(char *text, const char *mot, const char *mot2)
{
    int exist = -1, i = 0, l = Longueur(text), m = Longueur(mot), m2 = Longueur(mot2);
    while (exist == -1 && i < (l - m + 1))
    {
        if (text[i] == mot[0])
        {
            int j = 1;
            while ((i + j) < l && j < m && text[i + j] == mot[j])
                j++;
            if (j == m)
                exist = i;
        }
        i++;
    }
    if (exist == -1)
    {
        printf("mot introuvable");
        return;
    }
    int d = m - m2;
    if (d > 0)
        for (i = exist + m2; i < l; i++)
            text[i] = text[i + d];

    else if (d < 0)
        for (i = l - d; i > exist + m2 - 1; i--)
            text[i] = text[i + d];
    d = 0;
    for (i = exist; i < exist + m2; i++)
    {
        text[i] = mot2[d];
        d++;
    }
}
/* 8- Une fonction qui v�rifie si un mot donn� est un Palindrome */
int Palindrome(const char *text)
{
    int p = 1, i = 0, l = Longueur(text);
    while (p && i < l / 2)
    {
        if (text[i] != text[l - i - 1])
            p = 0;
        i++;
    }
    return p;
}
/* 9- le mot le plus long dans le texte */
char *motPlusLong(const char *text)
{
    int i = 0, l = Longueur(text), j = 0, p = 0, max = 0;
    if (l > 0 && !(text[0] == ' ' || text[0] == '\t'))
        j++;
    while (i < l)
    {
        if (!(text[i] == ' ' || text[i] == '\t'))
        {
            j = 1;
            while (!(text[i + j] == ' ' || text[i + j] == '\t'))
                j++;
            if (j > max)
            {
                max = j;
                p = i;
            }
        }
        else
            j = 1;
        i += j;
    }

    //allocation de tableau
    char *mot = (char *)malloc(sizeof(char) * (max + 1));
    for (i = 0; i < max; i++)
        mot[i] = text[i + p];
    mot[max] = '\0';
    return mot;
}
/* 10- les caract�res de text et ces occurrences */
int ajoutT(char *T, char c)
{
    int l = Longueur(T);
    T[l] = c;
    T[l + 1] = '\0';
    return l;
}
int verfierExistance(char *T, char c)
{
    int i = 0;
    while (T[i] != c && T[i] != '\0')
        i++;
    if (T[i] == c)
        return i;
    return 0;
}
void CaractereOccurrences(const char *text, char *T, int *V)
{
    int i, p;
    T[0] = '\0';
    for (i = 0; text[i] != '\0'; i++)
    {
        p = verfierExistance(T, text[i]);
        if (p == 0)
        {
            p = ajoutT(T, text[i]);
            V[p] = 1;
        }
        else
            V[p]++;
    }
    p = Longueur(T);
    for (i = 0; i < p; i++)
    {
        printf("%c - %d \n", T[i], V[i]);
    }
}
void Menu(const char *text)
{
    printf("\n\n ---------------------------------------------------------\n");
    if (Longueur(text) > 0)
    {
        printf("notre text est : %s \n\n", text);
        printf("0.  Resaiser le text .\n");
    }
    else
    {
        printf("Le text est n'est pas saisser \n\n");
        printf("0.  Saiser le text .\n");
    }
    printf("1.  La longueur de la chaine de de caracteres (nombre de caracteres).\n");
    printf("2.  Le nombre de mots du texte (de la chaine de caracteres). \n");
    printf("3.  Le nombre de caracteres numeriques dans le texte. \n");
    printf("4.  Remplace un caractere par un autre.\n");
    printf("5.  Insere un mot a une position donnee du texte.\n");
    printf("6.  Verifie l'existence d'un mot dans le texte.\n");
    printf("7.  Remplace un mot par un autre mot.\n");
    printf("8.  Verifie si un mot donne Palindrome. \n");
    printf("9.  Le mot le plus long dans le texte.\n");
    printf("10  Les caracteres et leur nombre d'occurrence dans le texte.\n");
    printf("*.  Entre un autre caractere pour quitee.\n\n");
}
int main()
{
    char text[Longueur_Max], T[Longueur_Max_T], mot[Longueur_Max_Mot];
    int V[Longueur_Max_T], choix = 0;
    text[0] = '\0';
    while (1)
    {
        Menu(text);
        printf("Entre votre choix: ");
        scanf("%d", &choix);
        fflush(stdin);
        switch (choix)
        {
        case 0:
        {
            printf("Entre le text :");
            scanf("%[^\n]s", text);
            fflush(stdin);
        }
        break;
        case 1:
        {
            printf("la longueur est %d\n", Longueur(text));
        }
        break;
        case 2:
        {
            printf("le nombre de mots du texte est: %d\n", NbrDesMots(text));
        }
        break;
        case 3:
        {
            printf("le nombre de caractères numériques dans le texte est: %d\n", NbrNum(text));
        }
        break;
        case 4:
        {
            char c1, c2;
            printf("Entre caracteres qui vous voulez le change :");
            scanf("%c", &c1);
            fflush(stdin);
            printf("Entre caracteres qui vous voulez le change par :");
            scanf("%c", &c2);
            fflush(stdin);
            RemplaceC(text, c1, c2);
        }
        break;
        case 5:
        {
            printf("insère un mot à une position donnée du texte,\n Entre le mot : ");
            scanf("%[^\n]s", mot);
            fflush(stdin);
            int position;
            printf("n   Entre la position ou vous voulez insere: ");
            scanf("%d", &position);
            fflush(stdin);
            InsereUnMot(text, mot, position);
        }
        break;
        case 6:
        {
            printf("vérifie l’existence d’un mot dans le texte,\n   Entre le mot :");
            scanf("%s", mot);
            fflush(stdin);
            printf("%s", mot);
            int exist = MotExist(text, mot);
            if (exist == 1)
                printf("le mot exist.\n");
            else
                printf("le mot ne exist pas.\n");
        }
        break;
        case 7:
        {
            printf("remplace un mot par un autre mot. \n    Entrez le mot que vous voulez remplacer :");
            scanf("%s", mot);
            fflush(stdin);
            char mot2[Longueur_Max_Mot];
            printf("    Entrez le mot que vous voulez remplacer par :");
            scanf("%s", mot2);
            fflush(stdin);
            RemplaceM(text, mot, mot2);
        }
        break;
        case 8:
        {
            printf("vérifie si un mot donné Palindrome. \n    Entrez le mot :");
            scanf("%s", mot);
            fflush(stdin);
            printf("le mot %s est %s\n", mot, Palindrome(mot) != 0 ? "palandrome" : "n'est pas palandrome");
        }
        break;
        case 9:
        {
            printf("le mot le plus long dans le texte est: %s\n", motPlusLong(text));
        }
        break;
        case 10:
        {
            CaractereOccurrences(text, T, V);
        }
        break;
        default:
        {
            return 0;
        }
        }
        system("pause");
    }

    return 0;
}
