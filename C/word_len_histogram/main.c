#include <stdio.h>

/* ���������� ��������� ��� ������ ����������� ���� ���� �������� ������ (����. 30 ��������) */

#define STATE_IN  1
#define STATE_OUT 0
#define MAX_LEN 31

int main()
{
    int max_len, cstate, clen;
    char c;
    int len_values[MAX_LEN];

    for (int i = 0; i < MAX_LEN; ++i)
        len_values[i] = 0;

    /* ���� ���� � ������������� ������� �������� � ������ */
    cstate = clen = 0;
    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\n' || c == '\t')
        {
            cstate = STATE_OUT;
            ++len_values[clen];
            clen = 0;
        }
        else if (cstate == STATE_OUT)
        {
            cstate = STATE_IN;
            ++clen;
        }
        else
            ++clen;

    /* ����������� ������������ ����������� ����� ����� */
    max_len = 0;
    for (int i = 1; i < MAX_LEN; ++i)
        if (len_values[i] > max_len)
            max_len = len_values[i];

    /* ����� ����� ����������: ����� ����� ����� (����� ������) �������������
    ������������� ���������� ����� �����, ��� ������� ������� ��������� ������,
    ���� ���������� ���� ������ ����� �� ������ ������ ������ (������ �����)*/
    putchar('\n');
    for (int i = max_len; i > 0; --i)
    {
        for (int len = 1; len < MAX_LEN; ++len)
        {
            if (len_values[len] >= i)
                putchar('*');
            else
                putchar(' ');
            putchar(' ');
        }
        putchar('\n');
    }

    /* ����� �������� ������ (� ��� ����) */
    for (int i = 1; i < MAX_LEN; ++i)
        printf("%d ", i/10);
    putchar('\n');
    for (int i = 1; i < MAX_LEN; ++i)
        printf("%d ", i%10);
    putchar('\n');

    return 0;
}
