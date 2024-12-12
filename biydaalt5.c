#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showSalesData(int numTransactions)
{
    srand(time(0));
    double(*transactions)[3] = malloc(numTransactions * sizeof(*transactions));

    for (int i = 0; i < numTransactions; i++)
    {
        double price = rand() % 100 + 1;
        double quantity = rand() % 10 + 1;
        double total = price * quantity;

        transactions[i][0] = price;
        transactions[i][1] = quantity;
        transactions[i][2] = total;
    }

    printf("Гүйлгээний дэлгэрэнгүй:\n");
    for (int i = 0; i < numTransactions; i++)
    {
        printf("Гүйлгээ %d: ", i + 1);
        printf("Үнэ: %.2f₮, ", transactions[i][0]);
        printf("Тоо хэмжээ: %.2f, ", transactions[i][1]);
        printf("Нийт: %.2f₮\n", transactions[i][2]);
    }

    free(transactions);
}

void showStudentGrades(int numStudents)
{
    srand(time(0));
    int(*grades)[3] = malloc(numStudents * sizeof(*grades));

    for (int i = 0; i < numStudents; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grades[i][j] = rand() % 51 + 50;
        }
    }

    printf("Сурагчдын дүн:\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("Сурагч %d: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            char grade;
            if (grades[i][j] >= 85)
                grade = 'A';
            else if (grades[i][j] >= 70)
                grade = 'B';
            else
                grade = 'C';

            printf("Хичээл %d: %c (%d) ", j + 1, grade, grades[i][j]);
        }
        printf("\n");
    }

    free(grades);
}

void showBankAccountTransactions(int numCustomers)
{
    srand(time(0));
    double(*transactions)[10] = malloc(numCustomers * sizeof(*transactions));

    for (int i = 0; i < numCustomers; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            transactions[i][j] = rand() % 201 - 100;
        }
    }

    printf("Банкны гүйлгээ:\n");
    for (int i = 0; i < numCustomers; i++)
    {
        printf("Хэрэглэгч %d Гүйлгээ: ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%.2f₮ ", transactions[i][j]);
        }
        printf("\n");
    }

    free(transactions);
}

void showSeatingChart(int rows, int seatsPerRow)
{
    srand(time(0));
    int(*seating)[seatsPerRow] = malloc(rows * sizeof(*seating));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < seatsPerRow; j++)
        {
            seating[i][j] = rand() % 2;
        }
    }

    printf("Суудлын мэдээлэл (0 = Боломжтой, 1 = Захиалсан):\n");
    for (int i = 0; i < rows; i++)
    {
        printf("Эгнээ %d: ", i + 1);
        for (int j = 0; j < seatsPerRow; j++)
        {
            printf("%d ", seating[i][j]);
        }
        printf("\n");
    }

    free(seating);
}

void showWeatherData(int days, int cities)
{
    srand(time(0));
    double(*temperatures)[cities] = malloc(days * sizeof(*temperatures));

    for (int i = 0; i < days; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            temperatures[i][j] = rand() % 51 - 10;
        }
    }

    printf("Цаг агаар (Өдөр x Хот):\n");
    for (int i = 0; i < days; i++)
    {
        printf("Өдөр %d: ", i + 1);
        for (int j = 0; j < cities; j++)
        {
            printf("%.1f°C ", temperatures[i][j]);
        }
        printf("\n");
    }

    free(temperatures);
}

int main()
{
    int choice;
    int num;

    printf("Та дараах боломжуудаас сонгоно уу:\n");
    printf("1. Гүйлгээний дэлгэрэнгүй\n");
    printf("2. Сурагчдын дүн\n");
    printf("3. Банкны гүйлгээ\n");
    printf("4. Суудлын мэдээлэл\n");
    printf("5. Цаг агаар\n");
    printf("Таны сонголт: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Гүйлгээний тоо оруулна уу: ");
        scanf("%d", &num);
        showSalesData(num);
        break;

    case 2:
        printf("Сурагчдын тоо оруулна уу: ");
        scanf("%d", &num);
        showStudentGrades(num);
        break;

    case 3:
        printf("Хэрэглэгчийн тоо оруулна уу: ");
        scanf("%d", &num);
        showBankAccountTransactions(num);
        break;

    case 4:
    {
        int rows, seatsPerRow;
        printf("Эгнээний тоо оруулна уу: ");
        scanf("%d", &rows);
        printf("Эгнээнд суудлын тоо оруулна уу: ");
        scanf("%d", &seatsPerRow);
        showSeatingChart(rows, seatsPerRow);
        break;
    }

    case 5:
    {
        int days, cities;
        printf("Өдөр бүрийн тоо оруулна уу: ");
        scanf("%d", &days);
        printf("Хотуудын тоо оруулна уу: ");
        scanf("%d", &cities);
        showWeatherData(days, cities);
        break;
    }

    default:
        printf("Хэвийн бус сонголт! Системээс гарах.\n");
        break;
    }

    return 0;
}
