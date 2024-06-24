#include <stdio.h>
#include <stdlib.h>
struct n{
    int x; //veriyi tutmak için
    struct n*next;
};
typedef struct n node;

//Linked listin in  içeriğini alıp onu bastırır.
void bastir(node * r){
    while(r != NULL){
        printf("%d ", r->x);
        r = r -> next;
    }
}
int main() {
    //bağlı listenin herhangi bir elemanına erişmek için önce ilk elemanına erişmek gerekir bu yüzden önce root yaptık
    node * root;
    //root un gösterdiği yere ilk kutuyu koyuyoruz
    root = (node *)malloc(sizeof(node));
    //başlangıç düğümün datasına veri yazdık
    root->x = 10;
    //2. düğümü oluşturuyoruz
    root -> next = (node *) malloc(sizeof(node));
    root -> next -> x = 20;
    root -> next -> next = (node *) malloc(sizeof(node));
    root -> next -> next -> x = 30;
    root -> next -> next -> next = NULL; //linked listin sonuna geldiğimizi hatayı önlemek için belirtmemiz gerekir
    //yukarıdaki şekilde tek tek düğümler oluşturup veriler yazabiliriz ama uzun işlemlerde bunu yapmak zorlaşıyor. Bunu kolaylaştırmak için bir tane daha root gibi pointer oluşturuyoruz.(iter)
    node * iter;
    iter = root ; //root un gösterdiği yeri iter de göstersin
    printf("%d ", iter -> x);//10
    iter = iter -> next;
    printf("%d\n",iter -> x );//20
    iter = root;
    int i = 0;

    /*while(iter != NULL){//koşul liste sonuna gelmemek
        i++;
        printf("%dninci eleman : %d \n", i, iter -> x);
        iter = iter -> next; //bağlı liste üzerinde bir sonraki düğüme ilerler
    }   çıktı
        1ninci eleman : 10
        2ninci eleman : 20
        3ninci eleman : 30        */


//listenin sonuna eleman eklemek istenirse sondaki kutuyu gösteren bir değer ihtiyaç vardır
    while (iter -> next != NULL){
        i++;
        printf("%dninci eleman : %d\n", i, iter -> x);
        iter = iter -> next;
    }
    for(i=0 ; i<5 ; i++){
        iter -> next = (node *)malloc(sizeof(node));
        iter = iter -> next;
        iter -> x = i*10;
        iter -> next = NULL;
    }
    bastir(root);
}
