#include "foo.h"

int main(void)
char *name_main = "bar";
printf("name_main atrašanas vieta atmiņā: %s\n", name_main);
printf("name_main vērtība pirms foo izpildīšanas: %s\n", name_main);
int id_main = 42

printf("id_main atrašanas vieta atmiņa: %s\n", &id_main);
printf("id_main vērtība pirms foo izpildīšanas:%s\n", id_main);

foo(id_main, name_main);
printf("id_main atrašanās vieta: %s\n", %id_main);
printf("id_main vērtība pēc foo izpildīšanas: %s\n", id_main);

printf("id_main atrašanās vieta: %s\n", name_main);
printf("id_main vērtība pēc foo izpildīšanas: %s\n", name_main);


    foo(42, "bar");
    return 0;
}
