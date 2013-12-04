#include <stdio.h>
#define MAX 30

void main()
{
	int procesos[MAX], bloques1[MAX], num_procesos, num_bloques;
	int opcion, bloques2[MAX], bloques3[MAX], bloques4[MAX];
	int bquick1[MAX/3], bquick2[MAX/3], bquick3[MAX/3];
	int p_count, b_count;
	int i, j;
	for(i=0; i< MAX/3; i++)
	{
		bquick1[i] = 4000;
	}
	for(i=0; i< MAX/3; i++)
	{
		bquick2[i] = 8000;
	}
	for(i=0; i< MAX/3; i++)
	{
		bquick3[i] = 12000;
	}
	Inicio:
	printf("\nIngrese el numero de procesos:  ");
	scanf("%d", &num_procesos);
	printf("\nIngrese el numero de bloques de memoria:  ");
	scanf("%d", &num_bloques);
	printf("\nIngrese el tamano de cada proceso:\n");
	for(p_count = 0;p_count<num_procesos; p_count++)
	{
		printf("Proceso %d: ", p_count+1);
		scanf("%d", &procesos[p_count]);
	}
	printf("\nIngrese el tamano de cada bloque de memoria:\n");
	for(b_count = 0;b_count<num_bloques; b_count++)
	{
		printf("Bloque %d: ", b_count+1);
		scanf("%d", &bloques1[b_count]);
		bloques4[b_count] = bloques2[b_count] = bloques3[b_count] = bloques1[b_count];
	}
	if(num_procesos<=num_bloques)
	{
		do
		{
			printf("\n\nAlgoritmos para asignar memoria: \n1. Primer ajuste\n2. Siguiente ajuste\n3. Mejor ajuste\n4. Peor ajuste\n5. Ajuste rapido\n\nIngrese el numero de su eleccion: ");
			scanf("%d", &opcion);
			switch(opcion)
			{
				//First fit
				case 1: printf("\nPrimer ajuste");
				for(p_count=0;p_count<num_procesos;p_count++)
				{
					for(b_count=0;b_count<num_bloques;b_count++)
					{
						if(procesos[p_count]<=bloques1[b_count])
						{
							printf("\nAsignar %d", procesos[p_count]);
							printf("\nProceso %d de tamano %d se asigno al bloque %d de tamano %d", p_count+1, procesos[p_count], b_count+1, bloques1[b_count]);
							bloques1[b_count]=0;
							break;
						}
					}
				}
				break;
				//Next fit
				case 2: printf("\nSiguiente ajuste");
				b_count = 0;
				for(p_count=0; p_count<num_procesos; p_count++)
				{
					for(b_count=0; b_count<num_bloques; b_count++)
					{
						if(procesos[p_count]<=bloques2[b_count])
						{
							printf("\nAsignar %d", procesos[p_count]);
							printf("\nProceso %d de tamano %d se asigno al bloque %d de tamano %d", p_count+1, procesos[p_count], b_count+1, bloques2[b_count]);
							bloques2[b_count]=0;
							break;
						}
						b_count = (b_count+1)%num_bloques;
					}
				}
				break;	
				//Best fit
				case 3: printf("\nMejor ajuste");
				for(p_count = 0; p_count < num_bloques; p_count++)
				{
					for(b_count = p_count +1; b_count < num_bloques; b_count++)
					{
						if(bloques3[p_count] > bloques3[b_count])
						{
							int temporal = bloques3[p_count];
							bloques3[p_count] = bloques3[b_count];
							bloques3[b_count] = temporal;
						}
					}
				}
				for(p_count = 0; p_count<num_procesos; p_count++)
				{
					for(b_count = 0; b_count<num_bloques; b_count++)
					{
						if(procesos[p_count]<= bloques3[b_count])
						{
							printf("\nAsignar %d", procesos[p_count]);
							printf("\nProceso %d de tamano %d se asigno al bloque %d de tamano %d", p_count+1, procesos[p_count], b_count+1, bloques3[b_count]);
							bloques3[b_count]=0;
							break;
						}	
					}
				}
				break;

				//Worst fit
				case 4: printf("\nPeor ajuste");
				for(p_count = 0; p_count < num_bloques; p_count++)
				{
					for(b_count = p_count +1; b_count < num_bloques; b_count++)
					{
						if(bloques4[p_count] < bloques4[b_count])
						{
							int temporal = bloques4[p_count];
							bloques4[p_count] = bloques4[b_count];
							bloques4[b_count] = temporal;
						}
					}
				}
				for(p_count = 0; p_count<num_procesos; p_count++)
				{
					j = 0;
					for(b_count = 0; b_count<num_bloques; b_count++)
					{
						if(procesos[p_count]<= bloques4[b_count])
						{
							printf("\nAsignar %d", procesos[p_count]);
							printf("\nProceso %d de tamano %d se asigno al bloque %d de tamano %d", p_count+1, procesos[p_count], b_count+1, bloques4[b_count]);
							bloques4[b_count]=0;
							j = 1;
							break;

						}
						
					}
					if(j==0)
					{
						printf("\nNo se pudo asignar el proceso %d de tamano %d", p_count+1, procesos[p_count]);
						bloques4[b_count]=0;
						break;
					}	
				}
				break;






				//Quick fit 4KB 8KB y 12KB
				case 5: printf("\nAjuste rapido");
				for(p_count=0;p_count<num_procesos;p_count++)
				{
					for(b_count=0;b_count<MAX/3;b_count++)
					{

					if(procesos[p_count]<=bquick1[b_count])
					{
						printf("\nAsignar %d", procesos[p_count]);
						printf("\nProceso %d de tamano %d se asigno al bloque %d de tamano %d", p_count+1, procesos[p_count], b_count+1, bquick1[b_count]);
						bquick1[b_count]=0;
						break;
					}
					else if(procesos[p_count]<=bquick2[b_count])
					{
						printf("\nAsignar %d", procesos[p_count]);							printf("\nProceso %d de tamano %d se asigno al bloque %d de tamano %d", p_count+1, procesos[p_count], b_count+1, bquick2[b_count]);
						bquick2[b_count]=0;
						break;
					}
									
					else if(procesos[p_count]<=bquick3[b_count])
					{
						printf("\nAsignar %d", procesos[p_count]);
						printf("\nProceso %d de tamano %d se asigno al bloque %d de tamano %d", p_count+1, procesos[p_count], b_count+1, bquick3[b_count]);
						bquick3[b_count]=0;
						break;
					}
					}				
		
				}
				break;	
				default:printf("Opcion invalida");
				break;
				
			}
		}
			while(opcion <= 5);
	}
	else
	{
		printf("\nIngrese un numero de bloques de memoria mayor al numero de procesos");
		goto Inicio;
	}

}
