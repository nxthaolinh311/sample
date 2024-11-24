
#include <stdio.h>

 /* Define struct */
struct w {
    float w1;
};

struct h{
    float *h1;
};

struct e {
    int *s;
};
struct in4 {
    char name[50];
    int *old;
    struct w weight;
    struct h hight;
    struct e *tthn;
};



/* Function check in4 */
int check_in4 (struct in4 *correct, struct in4 *test){
    int true = 1;                                               // true:1; false:0
    for (int i=0; ; i++){
        if(correct->name[i] != test->name[i]){
            true = 0;
        }
        break;
    }
    if(*(correct->old) != *(test->old))                 true=0;               
    if((correct->weight.w1) != (test->weight.w1))       true=0;
    if(*(correct->hight.h1) != *(test->hight.h1))       true=0;
    if(*(correct->tthn->s) != *(test->tthn->s))         true=0;

    return true;
}

/*------------------------------------------------*/
int main (){
    int o[10]={24,24,24,24,23,30,24,24,24,24};

    struct w weight_test[10]={42,50,53,70,72,50.2,52,60,74,46};

    float h_t[10]={1.53,1.53,1.53,1.7,1.72,1.53,1.6,1.65,1.8,1.53};
    struct h hight_test[10];
    for(int i=0; i<10; i++){
        hight_test[i].h1 = &h_t[i];
    }

    int t[10]={1,0,0,1,0,1,1,0,0,0};
    struct e tthn_test[10];
    for(int i=0; i<10; i++){
        tthn_test[i].s = &t[i];
    }

    struct in4 correct = {"Thao Linh", &o[9], weight_test[9], hight_test[9], &tthn_test[9]};
    
    struct in4 test[10] = {
        {"Bao Tran", &o[0], weight_test[0], hight_test[0], &tthn_test[0]},
        {"Kim Khanh", &o[1], weight_test[1], hight_test[1], &tthn_test[1]},
        {"Le Chi", &o[2], weight_test[2], hight_test[2], &tthn_test[2]},
        {"Nhat Long", &o[3], weight_test[3], hight_test[3], &tthn_test[3]},
        {"Xuan Khoa", &o[4], weight_test[4], hight_test[4],&tthn_test[4]},
        {"Thanh Thao", &o[5], weight_test[5], hight_test[5],&tthn_test[5]},
        {"Bao Khanh",&o[6], weight_test[6], hight_test[6],&tthn_test[6]},
        {"Minh Tri", &o[7], weight_test[7], hight_test[7], &tthn_test[7]},
        {"Quang Kiet", &o[8], weight_test[8], hight_test[8],&tthn_test[8]},
        {"Thao Linh", &o[9], weight_test[9], hight_test[9],&tthn_test[9]} 
    };

        /* Check in4 */
        int check=0;
        for(int i=0; i<10; i++){
            if(check_in4(&correct, &test[i])){
                printf("Match:\n");
                printf("%s %d %f %f %d\n",test[i].name, *(test[i].old), test[i].weight.w1, *(test[i].hight.h1), *(test[i].tthn->s));
                check=1;
                break;
            } 
        }
        if(check == 0){
            printf("No match\n");
        }

    return 0;
}