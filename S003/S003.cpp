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
        //������ ������ ������
        lea ebx, s1
        push ebx
        lea ecx, f
        push ecx
        call scanf
        add esp, 8
        //������ ������ � ����� ��������
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
        //���������� � �������� ����� ������
        lea ebx, s1
        dec ebx
        mov ecx, -1
        //������� ����� ������
        b1:
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz b1
            //���������� � ������ ��������
            lea edx, s1
            dec edx
            //�������� ���������� ������� ��������
            mov eax, start
            cmp eax, ecx
            jge end
            cmp eax, 0
            jg skip
            mov eax, 0 //���� ��������� ������ ������ 0, �������� 0

            skip:
        //���������� � �����
        lea ebx, s1
            dec ebx
            lea edx, s2
            dec edx
            mov ecx, len
            inc eax
            push eax
            //�������� �� ��������� �����
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