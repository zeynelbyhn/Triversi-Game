#include <stdio.h>
#define SIZE 23
int main(void)
{
    int boyut, i, j, N, K, m, n, k, x, y, temp_x, temp_y, kirmizi, sari, mavi, kazanan, flag;
    char A[SIZE][SIZE];
    
    printf("Ilk olarak lutfen oyun tahtasinin boyutunu giriniz.\n");
    scanf("%d", &boyut);	
    while(boyut > 23){
    	printf("Oyun tahtasinin boyutu 23'den buyuk olamaz lutfen tekrar giriniz.\n");
    	scanf("%d", &boyut);
	}
	
    for (i = 0; i < boyut; i++)
    {
        for (j = 0; j < boyut; j++)
        {
            A[i][j] = '-';
        }
    }

    if (boyut % 2 == 0) // Eger girilen boyut degeri cift ise 4 haneye yerlestirebiliriz.
    {
        k = boyut / 2;
        printf("1. Oyuncu lutfen 'Kirmizi' tas icin koordinat giriniz.\n");
        scanf("%d %d", &n, &m);
        while (!((n - 1 == k - 1 && (m - 1 == k - 1 || m - 1 == k)) || (n - 1 == k && (m - 1 == k - 1 || m - 1 == k))))
        {
            printf("1. oyuncu lutfen 'Kirmizi' tasi tahtanin ortasina koyunuz.\n");
            scanf("%d %d", &n, &m);
        }
        A[n - 1][m - 1] = 'K';
        for (i = 0; i < boyut; i++)
        {
            for (j = 0; j < boyut; j++)
            {
                printf("%c ", A[i][j]);
            }
            printf("\n");
        }
    }
    else // Eger girilen boyut degeri tek ise ilk tas boyut degerinin ortancasina yerlestirilir. (ornek: 7+1/2=4)
    {
        k = (boyut / 2);
        printf("1. Oyuncu lutfen 'Kirmizi' tas icin koordinat giriniz.\n");
        scanf("%d %d", &n, &m);
        while (!(n - 1 == k && m - 1 == k)) // n ve m girilen satýr ve sutun indeksleri olmak uzere bunlardan 1 cikararak dizideki asil yerlerini belirttim.
        {
            printf("1. oyuncu lutfen 'Kirmizi' tasi tahtanin ortasina koyunuz.\n");
            scanf("%d %d", &n, &m);
        }
        A[n - 1][m - 1] = 'K';      // 1. Oyuncunun kullandigi tas Kirmizi.
        for (i = 0; i < boyut; i++) // 1. Oyuncunun yerlestirdigi tas sonrasi tahta duzeni.
        {
            for (j = 0; j < boyut; j++)
            {
                printf("%c ", A[i][j]);
            }
            printf("\n");
        }
    }
    // Girilen ilk degerin bitisi

    N = 2; // N adim sayisi, boyut*boyut ise toplam yapilacak hamle sayisi. (ornek: 7*7=49)
    while (N <= boyut * boyut)
    {
        x = N % 3;
        if (x == 1)
        {
            printf("1. Oyuncu lutfen 'Kirmizi' tasi yerlestirmek icin koordinat giriniz. \n");
        }
        else if (x == 2)
        {
            printf("2. Oyuncu lutfen 'Sari' tasi yerlestirmek icin koordinat giriniz. \n");
        }
        else
        {
            printf("3. Oyuncu lutfen 'Mavi' tasi yerlestirmek icin koordinat giriniz. \n");
        }

        scanf("%d %d", &n, &m);
        
        while(n > boyut || m > boyut){
        	printf("Tasiniz tahtaya yerlesmedi, lutfen tekrar koordinat giriniz. \n");
        	scanf("%d %d", &n, &m);
		}
		
        while (A[n - 1][m - 1] != '-')
        {
            printf("Bu kutucuk zaten dolu, lutfen tekrar koordinat giriniz. \n");
            scanf("%d %d", &n, &m);
        }
        
        while (!(A[n - 2][m - 2] == 'K' || A[n - 2][m - 2] == 'S' || A[n - 2][m - 2] == 'M' ||
                 A[n - 2][m - 1] == 'K' || A[n - 2][m - 1] == 'S' || A[n - 2][m - 1] == 'M' ||
                 A[n - 2][m] == 'K' || A[n - 2][m] == 'S' || A[n - 2][m] == 'M' ||
                 A[n - 1][m - 2] == 'K' || A[n - 1][m - 2] == 'S' || A[n - 1][m - 2] == 'M' ||
                 A[n - 1][m] == 'K' || A[n - 1][m] == 'S' || A[n - 1][m] == 'M' ||
                 A[n][m - 2] == 'K' || A[n][m - 2] == 'S' || A[n][m - 2] == 'M' ||
                 A[n][m - 1] == 'K' || A[n][m - 1] == 'S' || A[n][m - 1] == 'M' ||
                 A[n][m] == 'K' || A[n][m] == 'S' || A[n][m] == 'M')) // eger girilen (n-1,m-1) adresinin etrafindaki 8 kutucuktan birinde Kirmizi, Sari ya da Mavi tastan biri yoksa tekrar koordinat iste.
        {
            printf("Bu kutucuk diger kutularla baglantili degil, lutfen tekrar koordinat giriniz. \n");
            scanf("%d %d", &n, &m);
        }

        if (x == 0) // tum kontrolleri yaptik ve dogru tas yerlestirdik.
        {
            A[n - 1][m - 1] = 'M';
        }
        else if (x == 1)
        {
            A[n - 1][m - 1] = 'K';
        }
        else
        {
            A[n - 1][m - 1] = 'S';
        }
        /*
            Taslarin birbirine donusme durumlarini 8 farkli durum icin kontrol ettirdim.
        */

        // sola dogru kontrol
        flag = 0;
        x = m - 3;
        while (x >= 0 && flag == 0 && A[n - 1][m - 2] != '-' && (A[n - 1][x] == 'K' || A[n - 1][x] == 'M' || A[n - 1][x] == 'S'))
        {
            if (A[n - 1][x] == A[n - 1][m - 1])
            {
                for (i = x; i <= m - 1; i++)
                {
                    A[n - 1][i] = A[n - 1][m - 1];
                }
                flag = 1;
            }
            x--;
        }

        // sol yukariya dogru kontrol

        y = n - 3; // satir
        x = m - 3; // sutun
        flag = 0;
        while (x >= 0 && flag == 0 && y >= 0 && A[n - 2][m - 2] != '-' && (A[y][x] == 'K' || A[y][x] == 'M' || A[y][x] == 'S'))
        {
            temp_x = x;
            temp_y = y;
            if (A[temp_y][temp_x] == A[n - 1][m - 1])
            {
                while (temp_y < n - 1 && temp_x < m - 1)
                {
                    A[temp_y][temp_x] = A[n - 1][m - 1];
                    temp_y++;
                    temp_x++;
                }
                flag = 1;
            }
            y--;
            x--;
        }

        // yukari dogru kontrol
        flag = 0;
        y = n - 3;
        while (y >= 0 && flag == 0 && A[n - 2][m - 1] != '-' && (A[y][m - 1] == 'K' || A[y][m - 1] == 'M' || A[y][m - 1] == 'S'))
        {
            if (A[y][m - 1] == A[n - 1][m - 1])
            {
                for (i = y; i <= n - 1; i++)
                {
                    A[i][m - 1] = A[n - 1][m - 1];
                }
                flag = 1;
            }
            y--;
        }

        // sag yukariya dogru kontrol

        y = n - 3; // satir
        x = m + 1; // sutun
        flag = 0;
        while (x <= boyut && flag == 0 && y >= 0 && A[n - 2][m] != '-' && (A[y][x] == 'K' || A[y][x] == 'M' || A[y][x] == 'S'))
        {
            temp_x = x;
            temp_y = y;
            if (A[temp_y][temp_x] == A[n - 1][m - 1])
            {
                while (temp_y < n - 1 && temp_x > m - 1)
                {
                    A[temp_y][temp_x] = A[n - 1][m - 1];
                    temp_y++;
                    temp_x--;
                }
                flag = 1;
            }
            y--;
            x++;
        }

        // saga dogru kontrol
     	flag = 0;
        x = m + 1;
        while (x <= boyut && flag == 0 && A[n - 1][m] != '-' && (A[n - 1][x] == 'K' || A[n - 1][x] == 'M' || A[n - 1][x] == 'S'))
        {
            if (A[n - 1][x] == A[n - 1][m - 1])
            {
                for (i = x; i > m - 1; i--)
                {
                    A[n - 1][i] = A[n - 1][m - 1];
                }
                flag = 1;
            }
            x++;
        }

        // sag alta dogru kontrol

        x = m + 1;
        y = n + 1;
        flag = 0;
        while (x <= boyut && flag == 0 && y <= boyut && A[n][m] != '-' && (A[y][x] == 'K' || A[y][x] == 'M' || A[y][x] == 'S'))
        {
            if (A[y][x] == A[n - 1][m - 1])
            {
                temp_x = x;
                temp_y = y;
                while (temp_x > m - 1 && temp_y > n - 1)
                {
                    A[temp_y][temp_x] = A[n - 1][m - 1];
                    temp_x--;
                    temp_y--;
                }
                flag = 1;
            }
            x++;
            y++;
        }

        // asagi dogru kontrol 

        y = n + 1;
        flag = 0;
        while (y <= boyut && flag == 0 && A[n][m - 1] != '-' && (A[y][m - 1] == 'K' || A[y][m - 1] == 'M' || A[y][m - 1] == 'S'))
        {
            if (A[y][m - 1] == A[n - 1][m - 1])
            {
                for (i = y; i > n - 1; i--)
                {
                    A[i][m - 1] = A[n - 1][m - 1];
                }
                flag = 1;
            }
            y++;
        }

        // sol asagiya dogru kontrol 
        y = n + 1; // satir
        x = m - 3; // sutun
        flag = 0;
        while (x >= 0 && flag == 0 && y <= boyut && A[n][m - 2] != '-' && (A[y][x] == 'K' || A[y][x] == 'M' || A[y][x] == 'S'))
        {
            temp_x = x;
            temp_y = y;
            if (A[temp_y][temp_x] == A[n - 1][m - 1])
            {
                while (temp_y > n - 1 && temp_x < m - 1)
                {
                    A[temp_y][temp_x] = A[n - 1][m - 1];
                    temp_y--;
                    temp_x++;
                }
                flag = 1;
            }
            y++;
            x--;
        }

        N++;
        // son hali yazdir
        for (i = 0; i < boyut; i++)
        {
            for (j = 0; j < boyut; j++)
            {
                printf("%c ", A[i][j]);
            }
            printf("\n");
        }
    } // end while
	
	kirmizi = 0;
	mavi = 0;
	sari = 0;
	
	
    for (i = 0; i < boyut; i++) // tas sayilari
    {
        for (j = 0; j < boyut; j++)
        {
            if (A[i][j] == 'K')
            {
                kirmizi++;
            }
            else if (A[i][j] == 'S')
            {
                sari++;
            }
            else
            {
                mavi++;
            }
        }
    } // end for

    if (kirmizi > sari) // En cok bulunan tasi buldum
    {
        if (sari > mavi)
        {
            kazanan = 1;
        }
        else
        {
            if (kirmizi > mavi)
            {
                kazanan = 1;
            }
            else
            {
                kazanan = 3;
            }
        }
    }
    else
    {
        if (kirmizi > mavi)
        {
            kazanan = 2;
        }
        else
        {
            if (sari > mavi)
            {
                kazanan = 2;
            }
            else
            {
                kazanan = 3;
            }
        }
    }

    printf("OYUN BITTI.\n KIRMIZI tastan %d tane, \n SARI tastan %d tane, \n MAVI tastan %d tane bulunmaktadir. \n ", kirmizi, sari, mavi);
    printf("Kazanan %d. OYUNCU oldu! Tebrikler.", kazanan);
    
    return 0;
}


