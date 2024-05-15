#include <iostream>
using namespace std;

//5223600002 / Bernadus Hendry Haryuwardhana

struct Node
{
    int data;
    Node* prev;
    Node* next;
};
//Menyisipkan node sebagai simpul dari linked list.
void insertNode(Node*& head, Node*& tail, int data)
{
    Node* n=new Node();
    n->data=data;

    if(head==nullptr)
	{
        n->next=nullptr;
        n->prev=nullptr;
        head=n;
        tail=n;
    }
	else
	{
        n->next=head;
        head->prev=n;
        head=n;
    }
}
//Menampilkan Node (sebaiknya diisi lebih dari 1 node)
void tampil(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
	{
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout<<"head: "<<head->data<<" next: "<<head->next->data<<endl;
}
//Mencari simpul. 
void cari(Node* head, int data)
{
    Node* temp=head;
    int n=1;
    if(head==nullptr)
	{
        cout<<"Tidak ada list yang telah dibuat (opsi 1)"<<endl;
    }else{
        while(temp->data!=data)
		{
            if(temp->next==nullptr)
			{
                cout<<"data "<<data<<" tidak ditemukan"<<endl;
                break;
            }else{
                temp=temp->next;
            }
            n++;
        }
    }
    if(temp->data==data) cout<<"data "<<data<<" ditemukan di node ke-"<<n<<endl;
}
//Menghapus simpul tertentu. 
void hapusNode(Node*& head, Node*& tail, int data)
{
    Node* temp=new Node();
    temp=head;
    while(temp->data!=data)
	{
        temp=temp->next;
    }
    if(temp==head){
        head=head->next;
    }else if(temp==tail)
	{
        tail=tail->prev;
    }
	else
	{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    delete temp;
}
//Menghapus keseluruhan node
void hapus(Node*& head)
{
    while (head != nullptr)
	{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main()
{
    Node* head=nullptr;
    Node* tail=nullptr;

    int pilihan, data;

    do
	{
        cout << "Menu Pilihan:\n";
        cout << "1. Sisipkan Node di Awal\n";
        cout << "2. Tampilkan Node\n";
        cout << "3. Cari Node\n";
        cout << "4. Hapus Node (urut dari pembuatan opsi 1)\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin  >> pilihan;

        switch (pilihan) 
		{
            case 1:
                cout << "Input: ";
                cin >> data;
                insertNode(head, tail, data);
                break;
            case 2:
                cout << "Output: ";
                tampil(head);
                break;
            case 3:
                cout << "Cari: ";
                cin >> data;
                cari(head, data);
                break;
            case 4:
                cout << "Hapus node: ";
                cin >> data;
                hapusNode(head, tail, data);
                break;
            case 5:
                cout << "Keluar?\n";
                break;
            default:
                cout << "Salah. Isi lagi\n";
        }
    } while (pilihan != 5);

    hapus(head);

    return 0;

}
