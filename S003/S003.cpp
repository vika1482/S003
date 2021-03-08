#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    char s1[256];
    char s2[256];
    int start;
    int len;
    char f[] = "%s";
    char fd[] = "%d";
    _asm {
        //чтение первой строки
        lea ebx, s1
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //чтение начала и длины удаления
        lea ebx, start
        push ebx
        lea edx, fd
        push edx
        call scanf
        add esp, 8
        lea ebx, len
        push ebx
        lea edx, fd
        push edx
        call scanf
        add esp, 8
        //подготовка к подсчету длины строки
        lea ebx, s1
        dec ebx
        mov ecx, -1
        //подсчет длины строки
        b1:
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz b1
            //подготовка к началу удаления
            lea edx, s1
            dec edx
            //проверка стартового индекса удаления
            mov eax, start
            cmp eax, ecx
            jge end
            cmp eax, 0
            jg skip
            mov eax, 0 //если стартовый индекс меньше 0, помещаем 0

            skip:
        //подготовка к циклу
        lea ebx, s1
            dec ebx
            lea edx, s2
            dec edx
            mov ecx, len
            inc eax
            push eax
            //копируем не удаляемую часть
            del1 :
        pop eax
            inc ebx
            dec eax
            push eax
            cmp eax, 0
            jnz del3
            del2 :
        dec ecx
            inc ebx
            cmp ecx, 0
            jnz del2
            del3 :
        inc edx
            mov al, [ebx]
            mov[edx], al
            cmp al, 0
            jz end
            jmp del1

            end :
        inc edx
            mov[edx], 0
            lea ebx, s2
            push ebx
            lea ecx, f
            push ecx
            call printf
            add esp, 12
    }
}