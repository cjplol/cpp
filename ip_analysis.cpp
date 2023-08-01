#include<iostream>
#include <sstream>
#include<vector>
#include<bitset>

using namespace std;
class IP{
    public: //公有成员
        string ip_address; //ip地址
        string subnet_mask; //子网掩码
        string gateway; //网关

        IP(){  //构造函数（Constructer），在创建一个MyObject对象时，它的构造函数会被自动调用
            ip_address="10.32.155.99";
            subnet_mask="255.255.240.0";
            gateway="10.32.144.1";
        }

        string get_ip_address(){
            return ip_address;
        }

        char get_category(){
            char category;
            size_t pos=ip_address.find('.'); //找到第一个'.'在ip地址中的位置
            int a=stoi(ip_address.substr(0,pos)); //stoi:将字符串转为整形
            if (a>=0 && a<=127)
                category='A';
            if (a>=128 && a<=191)
                category='B';
            if (a>=192 && a<=255)
                category='C';

            return category;
        }

        //通过子网掩码返回划分的网段
        void get_segment_from_mask(){
            std::stringstream ss(subnet_mask);
            std::vector<int> bytes;
            std::string byte_str;
            char delimiter;

            while (getline(ss, byte_str, '.')) {
                bytes.push_back(std::stoi(byte_str));
            }
            for (int i = 0; i < bytes.size(); i++) {
                if (bytes[i]!=255){
                    
                }
                //std::cout << bytes[i] << " ";
            }
        }

        private: //私有成员
            //string ip_address;
            void dtob(){  //十进制转二进制

            }
};

int main(){
    IP ip;
    //cout<<ip.ip_address<<endl; //公有成员可以查看属性，私有成员不能，需要通过类方法调用
    // cout<<"请输入IP地址：";
    // cin>>ip.ip_address;
    cout<<"IP地址为："<<ip.get_ip_address()<<endl;
    cout<<"IP地址类别："<<ip.get_category()<<"类"<<endl;
    //cout<<"aaa"<<endl;
    ip.get_segment_from_mask();
    system("pause");
    return 0;
}
    