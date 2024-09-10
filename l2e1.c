    #include <stdio.h>
    #include <stdlib.h>


    int validacao_saque(int valor){
        if(valor==3 || valor ==1){
            return 1;
        }    

        return 0;
    }

    void saque(int valor,float saldo){
        int back;
        back = valor;

        int saquemenor[7];
        for(int c = 0 ; c < 6 ; c ++){
            saquemenor[c] = 0;
        }
        

        struct{
            int cinco,dois;
        }bolao;

        
        while(valor-100>=0){
            saquemenor[0] ++;
            valor-=100;
        }
        while(valor-50>=0){
            saquemenor[1] ++;
            valor-=50;
        }
        while(valor-20>=0){
            saquemenor[2] ++;
            valor-=20;
        }
        while(valor-10>=0 && valor-10!=1 && valor-10!=3){
            saquemenor[3] ++;
            valor-=10;
        }
        while(valor-5>=0 && (valor-5)%2!=1){
            saquemenor[4] ++;
            valor-=5;
        }
        while(valor-2>=0){
            saquemenor[5] ++;
            valor-=2;
        }



        if (back%2==1){
            bolao.cinco = 1;
            bolao.dois = (back-5)/2;
        }else{
            bolao.dois = back/2;
        }
        

        printf("RESULTADOS\n\n");
        printf("Valor atualizado do saldo (em reais): %.2f\n\n", (float)(saldo - back));
        printf("Opcao de saque 1 (menor quantidade possivel de cedulas)\n\n");
        for (int i = 0 ; i < 6 ; i++){
            switch (i)
            {
            case 0:
                if(saquemenor[0]!=0){
                    printf("Cedulas de 100 reais: %i\n\n",saquemenor[0]);
                }
                break;
            case 1:
                if(saquemenor[1]!=0){
                    printf("Cedulas de 50 reais: %i\n\n",saquemenor[1]);
                }
                break;
            case 2:
                if(saquemenor[2]!=0){
                    printf("Cedulas de 20 reais: %i\n\n",saquemenor[2]);
                }
                break;
            case 3:
                if(saquemenor[3]!=0){
                    printf("Cedulas de 10 reais: %i\n\n",saquemenor[3]);
                }
                break;
            case 4:
                if(saquemenor[4]!=0){
                    printf("Cedulas de 5 reais: %i\n\n",saquemenor[4]);
                }
                break;
            case 5:
                if(saquemenor[5]!=0){
                    printf("Cedulas de 2 reais: %i\n\n",saquemenor[5]);
                }
                break;
            }   
        }

        printf("Opcao de saque 2 (maior quantidade possivel de cedulas)\n\n");
        
        printf("Cedulas de 2 reais: %i\n\n",bolao.dois);
        if(bolao.cinco!=0){
            printf("Cedulas de 5 reais: %i\n\n",bolao.cinco);
        }
    }

    void main(){
        float saldo_usuario;
        int valor_saque;
        printf("Entre com o saldo da conta a ser sacada (em reais): ");
        scanf("%f",&saldo_usuario);

        do{
            printf("Entre com o valor do saque (em reais): ");
            scanf("%i",&valor_saque);


            if (valor_saque>saldo_usuario){
                printf("Saldo insuficiente para valor desejado");printf("\n\n");
                continue;
                
            }else if(valor_saque<=0){
                printf("Valor do saque invalido\n\n");
                continue;

            }else if(!validacao_saque){
                printf("Valor do saque incompatível com notas disponiveis\n\n");
                continue;

            }

        }while(valor_saque>saldo_usuario || !validacao_saque || valor_saque<=0);

        saque(valor_saque,saldo_usuario);

    }
