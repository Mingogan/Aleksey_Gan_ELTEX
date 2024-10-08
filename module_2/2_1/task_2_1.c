#include <stdio.h>

#define LEN_STR 50

typedef struct Phones
{
    char number[LEN_STR];
} Phones;

typedef struct Links
{
    char url[LEN_STR];
} Links;

typedef struct PhoneBook
{
    char firstName[LEN_STR];
    char lastName[LEN_STR];
    char patronymic[LEN_STR];
    char jobPlace[LEN_STR];
    char post[LEN_STR];
    char email[LEN_STR];
    Phones phones[5];
    int amountPhone;
    Links links[5];
    int amountLinks;

} PhoneBook;

PhoneBook phoneBook[50];
int amountContact = 0;


void printBook(){
    if (amountContact==0)
    {
        printf("Книга пуста\n");
    }
    
    for(int i=0;i<amountContact;i++){
        printf("Номер контакта: %d\n",i+1);
        printf("Имя: %s\n",phoneBook[i].firstName);
        printf("Фамилия: %s\n",phoneBook[i].lastName);
        printf("Отчество: %s\n",phoneBook[i].patronymic);
        printf("Место работы: %s\n",phoneBook[i].jobPlace);
        printf("Должность: %s\n",phoneBook[i].post);
        printf("Адрес email: %s\n",phoneBook[i].email);
        printf("Телефоны:\n");
        for(int j=0; j < phoneBook[i].amountPhone;j++){
            printf("\tНомер телефона %d: %s\n", j, phoneBook[i].phones[j].number);
        }
        printf("Ссылки:\n");
        for(int j=0; j < phoneBook[i].amountLinks;j++){
            printf("\tСсылка %d: %s\n", j, phoneBook[i].links[j].url);
        }

    }
}

void addContact(){
    if (amountContact == 50){
        printf("Переполнение телефонной книги\n");
        return;
    }
    
    printf("Введи имя \n");
    scanf("%s", phoneBook[amountContact].firstName);
    printf("Введи фамилию \n");
    scanf("%s", phoneBook[amountContact].lastName);
    amountContact++;
}

void deleteContact(){
    int id;
    printf("Введи номер контакта для удаления: ");
    scanf("%d",&id);
    id--;
    if(id<0||id>amountContact){
        printf("Введён неверный номер\n");
        return;
    }

    for(int i=id;i<=amountContact-1;i++){
        phoneBook[i]=phoneBook[i+1];
    }

    amountContact--;
}

void editContact(){
    int id;
    printf("Введи номер контакта для изменения: ");
    scanf("%d",&id);
    id--;

    if(id<0||id>amountContact-1){
        printf("Введён неверный номер\n");
        return;
    }

    printf("Текущее имя: %s \n", phoneBook[id].firstName);
    scanf("%s", phoneBook[amountContact].firstName);
    printf("Текущая фамилия: %s \n", phoneBook[id].lastName);
    scanf("%s", phoneBook[amountContact].lastName);
    printf("Текущее отчество: %s \n", phoneBook[id].patronymic);
    scanf("%s", phoneBook[amountContact].patronymic);
    printf("Текущее место работы: %s \n", phoneBook[id].jobPlace);
    scanf("%s", phoneBook[amountContact].jobPlace);
    printf("Текущая должность: %s \n", phoneBook[id].post);
    scanf("%s", phoneBook[amountContact].post);
    printf("Текущий введи email: %s \n", phoneBook[id].email);
    scanf("%s", phoneBook[amountContact].email);

    phoneBook[amountContact].amountPhone = 0;
    int choice = 1;
    while (phoneBook[amountContact].amountPhone < 5 && choice == 1)
    {
        printf("Введи номер телефона: ");
        scanf("%s", phoneBook[amountContact].phones[phoneBook[amountContact].amountPhone].number);
        phoneBook[amountContact].amountPhone++;
        choice = 0;
        if (phoneBook[amountContact].amountPhone < 5){
            printf("Чтобы добавить ещё номер нажмите 1: ");
            scanf("%d", &choice);
            while(getchar() != '\n');
        }
    }

    phoneBook[amountContact].amountLinks = 0;
    choice = 1;
    while (phoneBook[amountContact].amountLinks < 5 && choice == 1)
    {
        printf("Введи ссылку: ");
        scanf("%s", phoneBook[amountContact].links[phoneBook[amountContact].amountLinks].url);
        phoneBook[amountContact].amountLinks++;
        choice = 0;
        if (phoneBook[amountContact].amountLinks < 5){
            printf("Чтобы добавить ещё ссылку нажмите 1: ");
            scanf("%d", &choice);
            getchar();
        }
    }
}


int main(){
    int choice = 0;
    do{
        printf("задание 2.1 - Телефонная книга \n\n");
        printf("1. Вывести список контактов\n");
        printf("2. Добавить контакт\n");
        printf("3. Изменить контакт\n");
        printf("4. Удалить контакт\n");
        printf("0. Выход\n");
        printf("Выбери действие \n\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printBook();
            break;
        case 2:
            addContact();
            break;
        case 3:
            editContact();
            break;
        case 4:
            deleteContact();
            break;
        case 0:
            break;
        default:
            printf("Неверный ввод, введи число от 0 до 4");
        }
    }while(choice != 0);

    return 0;
}