# Get Next Line

Fonction C lisant une ligne d'un descripteur de fichier.

## 🚀 Utilisation

### Compilation avec votre projet
\`\`\`bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
\`\`\`

### Fonction
\`\`\`c
char *get_next_line(int fd);
\`\`\`

## 📚 Fonctionnalités

- Lecture ligne par ligne (avec gestion du buffer)
- Compatible avec fichiers et stdin
- Gestion correcte des sauts de ligne
- Pas de fuite mémoire

## 🛠️ Compilation

Définir le BUFFER_SIZE :
\`\`\`bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
\`\`\`

## 🔧 Technologies

- C
