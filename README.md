# 🐍 Snake Game în C

Un joc clasic Snake implementat în C pentru terminalul Windows.  
Șarpele se mișcă pe o tablă pătrată, mănâncă mâncare (`F`) și crește. Jocul se termină dacă șarpele lovește pereții sau propria coadă.

## ✨ Funcționalități

- Mișcare cu tastele **W/A/S/D**  
- Creștere șarpe când mănâncă mâncarea (`F`)  
- Coliziune cu pereții sau coada → Game Over  
- Scor afișat permanent  
- Input rapid și răspuns instant

## 📁 Structura Proiectului

- `main.c` – Punctul de intrare și bucla principală a jocului  
- `snake.c` – Implementarea logicii jocului  
- `snake.h` – Declarațiile funcțiilor și variabilelor globale  

## 🚀 Cum se compilează și rulează

1. Deschide terminalul în folderul proiectului  
2. Compilează proiectul cu GCC:

```bash
gcc main.c snake.c -o snake.exe
