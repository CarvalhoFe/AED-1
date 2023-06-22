#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main (){
	 int casos, numPessoas;
	char atual[21], anterior[21];
	bool ingles;

	scanf("%d", &casos);

	while(casos--){

		scanf("%d", &numPessoas);
		scanf(" %s", atual);

		numPessoas--;
		ingles = false;
		strcpy(anterior, atual);
		while(numPessoas--){

			if(strcmp(atual, anterior) != 0 && ingles == false)
				ingles = true;
			else
				strcpy(anterior, atual);

			scanf(" %s", atual);

		}

		if(ingles)
			printf("ingles\n");
		else
			printf("%s\n", atual);

		ingles = false;

	}
  return 0;
}
