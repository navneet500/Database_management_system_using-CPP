//create table student(GRNO int , Name varchar , Phone int , Branch varchar );
//create table employees(ID int , Name varchar , Phone int , Dept varchar );
//drop table student;



# include <bits/stdc++.h>
# include <iostream>
# include <fstream>
# include <string.h>
# define MAX 10
using namespace std;
int k=0;
ofstream Dictionary;
string cols[MAX][2];
void create(string q);
void insert_record(string q);
void update_record(string q);
void delete_record(string q);
void describe(string q);
void truncate(string q);
void drop(string q);
void select(string q);
int checktable(string t);
void help();

int main() {

    string query = "", temp;
    int i = 0;


    do {
        i = 0;
        temp = "";

        cout << "\n Enter the Query : > " ;
        getline(cin, query);

        transform(query.begin(), query.end(), query.begin(), ::tolower);

        if(query[i] == 'h') {
            while(query[i] != ';') {
               temp += query[i];
               i++;
            }
        }
        else {
            while(query[i] != 32) {
               temp += query[i];
               i++;
            }
        }

        string q1 = query.substr(i, query.length());

        if(temp == "create") {
            create(q1);
        }

        else if(temp=="drop")
        {
            drop(q1);
        }

        else if(temp == "insert") {
            insert_record(q1);
        }

        else if(temp == "update") {
            update_record(q1);
        }

        else if(temp == "delete") {
            delete_record(q1);
        }

        else if(temp == "desc" || temp == "describe") {

            describe(q1);
        }

        else if(temp=="trunc" || temp=="truncate")
        {
            truncate(q1);
        }
        
        else if(temp=="select")
        {
           select(q1);
        }
        
        else if(temp == "help")
        {
            help();
        }

        else if(temp == "exit") {
            exit(0);
        }

        else {
            cout << "\n ERR: Please enter valid statement..! " ;
        }

    } while(1);

    return 0;
}

void create(string q)
{
    int i = 1, k = 0;
    string temp, tableName, columnName, dataType;

    string file = "Dict";

    while(q[i] != 32) {
       i++;
       //cout << i << endl;
    }
    i++;
    //cout << i ;
    while(q[i] != 40) {
       tableName += q[i];
       i++;
    }
    i++;

    //Exception - Check whether already table exist or not with similar name..
    //cout << "\n Table Name - " << tableName << endl;

    while(q[i] != 41) {
        columnName = "";
        dataType = "";

        while(q[i] != 32) {
            columnName += q[i];
            i++;
        }
        i++;
        cols[k][0] = columnName;

        while(q[i] != 44) {
            if(q[i] == 41) {
                break;
            }
            dataType += q[i];
            i++;
        }
        cols[k][1] = dataType;
        //cout << " col = " << cols[k][0] << " "<< cols[k][1] << endl ;
        k++;

        if((q[i] != 41)) {
            i += 2;
        }
        else {
            break;
        }
    }

    int flag=0;
    ofstream outfile;
    char data[100];

    ifstream dict;
    dict.open(file + ".txt", ios::out);

    while(!dict.eof())
    {
         dict.getline(data,100);

        string temp = "";
        int ii = 0;

        while(data[ii] != 35) {

            temp += data[ii];
            //cout << " \n temp - " << temp << endl ;
            ii++;
        }

         if(tableName == temp)
         {
             cout << "\n Table is already exists..! " << endl;
             flag=1;
             break;
         }
    }
    dict.close();

    Dictionary.open(file + ".txt", ios::app);

    if(flag==0)
    {
        outfile.open(tableName + ".txt");

        Dictionary << tableName << "#" ;

        for(i=0;i<k;i++)
        {
            Dictionary<<cols[i][0]<<"-";
            Dictionary<<cols[i][1]<<"|";
        }
        Dictionary << ";" << "\n" ;
        Dictionary.close();

        for( i = 0 ; i < k ; i++) {
            outfile << cols[i][0] << "|";
        }

        outfile << "\n" ;

        cout << "\n " << tableName<<" : Table Created Successfully..! " << endl;
     }

    outfile.close();
}

void drop(string q)
{
  int i=1;
  string tableName;

    while(q[i] != 32) {
       i++;
    
    }
    i++;


    while(q[i] != ';') {
       tableName += q[i];
       i++;

    }
    i++;

    string temp1 = tableName + ".txt";

    int n = temp1.length();

    char char_array[n + 1];

    strcpy(char_array, temp1.c_str());

    int result = remove(char_array);

    if (result == 0)
    {
        ifstream infile;
        ofstream outfile;
        string temp = "temp1";
        char data[100];

        infile.open("Dict.txt", ios::in);
        outfile.open(temp + ".txt", ios::out);

        while(!infile.eof()) {

            memset(data, 0, sizeof(data));
            infile.getline(data,100);
            cout << data << endl;
            string t;
            int i = 0 ;

            while(data[i] != 35) {
               t += data[i];
               i++;
            }
            cout << t << endl ;
            if(tableName != t) {
                outfile << data ;
            }
        }
        outfile.close();
        infile.close();

        infile.open(temp + ".txt", ios::in);
        outfile.open("Dict.txt", ios::out);

        while(!infile.eof()) {

            memset(data, 0, sizeof(data));
            infile.getline(data,100);
            outfile << data ;
        }
        outfile.close();
        infile.close();

        cout << "\n Table drop Successfully..! "<< endl;
    }
}


void help()
{
    string command;

    do {
        cout << "\n Command : " ;
        cin >> command;
        cout << endl << "    " ;
        transform(command.begin(), command.end(), command.begin(), ::tolower);

        if(command == "create")
        {
            cout << "CREATE TABLE table_name (column1 datatype, column2 datatype, column3 datatype, ....);"<<endl;
        }
        else if(command == "truncate" || command == "trunc")
        {
            cout << "TRUNCATE TABLE table_name;"<<endl;
        }
        else if(command == "drop")
        {
             cout << "DROP TABLE table_name;"<<endl;
        }
        else if(command == "delete")
        {
             cout << "DELETE FROM table_name WHERE condition;"<<endl;
        }
        else if(command == "update")
        {
             cout << "UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition;"<<endl;
        }
        else if(command == "describe" || command == "desc")
        {
             cout << "DESCRIBE table_name;"<<endl;
        }
        else if(command == "insert")
        {
             cout << "INSERT INTO table_name (column1, column2, column3, ...) VALUES (value1, value2, value3, ...);"<<endl;
        }
        else if(command == "select")
        {
           cout << "" << endl ;
        }
        else if(command == "help")
        {
            cout << "YOU ARE IN HELP COMMAND EXECUTION iTSELF.." << endl ;
        }
        else if(command == "exit") {
            break;
        }
        else {
            cout << " Please enter valid command.. " << endl ;
        }

    }while(1);
}

void select(string q1)
{
    ifstream infile;
    int i=1;
    char data[100];
    string tableName="";

    cout << endl ;

    if(q1[i]=='*')
    {
        i++;

        while(q1[i]!=' ')
        {
           i++;
        }
        i++;

        while(q1[i]!=' ')
        {
           i++;
        }
        i++;

        while(q1[i]!=';')
        {
           tableName+=q1[i];
           i++;
        }
        infile.open(tableName + ".txt", ios::in);

        while(!infile.eof())
        {
            infile.getline(data,100);
            cout << data ;
        }
        cout << endl ;
        infile.close();
    }
}

void describe(string q1)
{
    int i=1;
    int flag=0;
    char data[100];
    ifstream infile;
    string tableName;

    while(q1[i]!=';')
    {
        tableName+=q1[i];
        i++;

    }

    if(checktable(tableName))
     {
        //cout<<tableName;
        string temp="Dict";
        char ch;
        string tb_nm, col_nm, col_type;
        infile.open(temp + ".txt", ios::in);
        int i1,k,j,m;

        while(!infile.eof())
        {
            infile.getline(data,100);

            for( i1=0; data[i1]!=35 ;i1++)
            {
                tb_nm+=data[i1];
            }
            i1++;

            if(tb_nm == tableName)
            {
                cout << "\n " << data << endl ;

                /*cout<<"\n " << tb_nm << " : "<<endl;

                for(int j=i1; data[j]!=';' ;j++)
                {
                   col_nm += data[j];
                }

                for(int j=i1; data[j]!=';' ;j++)
                {
                   col_nm += data[j];
                }

                cout << " | " << col_nm << " - "<< col_type << " | " << endl;
                col_nm = "";*/
            }
            tb_nm = "";
        }
        infile.close();
    }
    else{
        cout<<"\n Table does not exists..! "<<endl;
   }
}



void truncate(string q )
{
    int i=1;
    char data[100];
    ofstream outfile;
    ifstream infile;
    string temp, tableName,temp2;
    temp2="temp";


    while(q[i] != 32) {
       i++;
       //cout << i << endl;
    }
    i++;

    //cout << i ;
    while(q[i] != ';') {
       tableName += q[i];
       i++;

    }
    i++;

if(checktable(tableName))
 {

    infile.open(tableName + ".txt",ios::in);
    outfile.open(temp2 + ".txt",ios::out);

    infile.getline(data,100);
    outfile<<data;

    outfile.close();
    infile.close();
    infile.open(temp2 + ".txt",ios::in);
    outfile.open(tableName + ".txt",ios::out);
    infile.getline(data,100);
    outfile<<data;

    cout<<"\n Truncated successfully..! " << endl;

 }
 else
 {
     cout<<"\n Table does not exists..! " <<endl;
 }
}

int checktable(string tblName)
{
    ifstream f;

    char data[100];
    int flag=0;

     f.open("Dict.txt", ios::in);

     while(!f.eof())
     {
        memset(data, 0, sizeof(data));
        f.getline(data, 100);
        string tableName;
        int i = 0 ;

        while(data[i] != 35) {
           tableName += data[i];
           i++;
        }

         if(tblName == tableName)
         {

             flag=1;
             break;
         }
     }
     if(flag==0)
     {
         return 0;
     }
     else{
        return 1;
     }

}



void insert_record(string q)
{
    /*
    -- insert into stud values(111, neha, 1234567890);
    */

    int i = 1;
    string temp, tableName, id, temp2;
    char data[100];
    int ids[100], no, no1, flag = 0;

    while(q[i] != 32) {
       i++;
    }
    i++;

    while(q[i] != 32) {
       tableName += q[i];
       i++;
    }
    i++;


    while(q[i] != 40) {
        //To skip 'values'
       i++;
    }
    i++;

    if(checktable(tableName))
    {
        ofstream outfile;
        outfile.open(tableName + ".txt", ios::app);

        /* while(q[i] != 41) {
        temp+=q[i];
        i++;
        } */

        /*int t = i;

        while(q[t] != 44) {
            id += q[t];
            t++;
        }
        t++;

        no = stoi(id);

        //cout << "\n id = " << no << endl ;
        int k = 0;

        ifstream ifs;
        ifs.open(tableName + ".txt", ios::in);
        ifs.getline(data,100);

        while(!ifs.eof())
        {
            ifs.getline(data,100);

            int j = 0;
            temp2 = "";

            while(data[j] != 124) {
                temp2 += data[j];
                j++;
            }
            //cout << endl << temp2 << endl ;

            no1 = stoi(temp2);
            ids[k] = no1;
            //cout << " | " << ids[k] << " = " << k ;
            k++;
        }

        ifs.close();

        for(int n = 0 ; n < k ; n++) {
            if(no == ids[n]) {
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            cout << "\n Primary Key Constraint Violated..! " << endl ;
        }
        else {*/
            while(q[i] != 41) {

                while(q[i] != 44) {

                    if(q[i] == 41) {
                        break;
                    }
                        temp += q[i];
                        i++;
                    }

                    outfile << temp << "|" ;
                    temp="";

                    if((q[i] != 41)) {
                        i += 2;
                    }
                    else {
                        break;
                    }
            }

            outfile<<temp;
            outfile << "\n" ;
            cout << tableName << " : Record inserted succesfully..!" << endl;
            outfile.close();
        //}
    }
    else
    {
        cout << "\n Table is not exists..! " << endl;
    }
}

void update_record(string q)
{

    string  tableName, colName, value, newColName, newValue, t = "";
    int i=1;
    ofstream outfile;
    ifstream infile;
    char data[100];
    string temp2;
    temp2="temp";

    //cout << "Query - " << q << endl ;
    //update stud set phone_no="9970149186" where name="shubhayu";
    //update stud set name="Nehali" where id="333";
    //update stud set name="Shubhayu" where id="222";

    while(q[i] != 32) {
       tableName += q[i];
       i++;
    }
    i++;

    cout << "\n " <<  tableName << endl ;

    if(checktable(tableName))
    {
        while(q[i] != 32) {

           i++;
        }
        i++;

        while(q[i] != 61) {

          newColName += q[i];
          i++;
        }
        i += 2;

        while(q[i] != 34) {

          newValue += q[i];
          i++;
        }
        i += 2;

        while(q[i] != 32) {

           i++;
        }
        i++;

        cout << "\n " << newColName << endl ;
        cout << " " <<  newValue << endl ;

        while(q[i] != 61) {

          colName += q[i];
          i++;
        }
        i += 2;

        while(q[i] != 34) {

          value += q[i];
          i++;
        }
        i++;

        cout << "\n " << colName << endl ;
        cout << " " <<  value << endl ;
    }
    else
    {
        cout<<"\n Table does not exists..! "<<endl;
    }

    ifstream is;
    int line_no = 1, count1 = 0, count2 = 0, ii = 0, flag = 0;
    string temp;

    memset(data, 0, sizeof(data));

    is.open(tableName + ".txt", ios::in);
    is.getline(data, 100);


    while(data[ii] != '\0') {
        temp = "" ;

        while(data[ii] != 124) {
            temp += data[ii];
   
            ii++;
        }
        ii++;
        count1++;

       

        if(temp == colName) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << "\n Column name specified doesn't exist..! " << endl ;
    }

    cout << "\n Count1 - " << count1 << endl ;

    flag = 0;
    ii = 0;
    memset(data, 0, sizeof(data));
    is.clear();
    is.seekg(0);
    is.getline(data, 100);

 
    while(data[ii] != '\0') {
        temp = "" ;

        while(data[ii] != 124) {
            temp += data[ii];
           
            ii++;
        }
        ii++;
        count2++;

        

        if(temp == newColName) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        cout << "\n Column name specified doesn't exist..! " << endl ;
    }

    cout << "\n Count2 - " << count2 << endl ;

    while(!is.eof()) {

        memset(data, 0, sizeof(data));
        is.getline(data,100);

        for(int n = 0 ; n < 3 ; n++) {
            cout << data[n] << " | ";
        }

        temp = "";
        line_no++;
        ii = 0;

        for(int k = 0 ; k < count1 ; k++) {
            temp = "" ;
            while(data[ii] != 124) {
                temp += data[ii];
                ii++;
            }
            ii++;
         
        }
        if(temp == value) {
            break;
        }
    }

    cout << "\n Line - " << line_no << endl ;

    is.clear();
    is.seekg(0);
    ofstream ofs;
    ofs.open("temp.txt", ios::out);

  
    char c;
    int n = 0, tt = 1;
    char arr[100];
    ii = 0;

    while (!is.eof())
    {
        memset(data, 0, sizeof(data));
        is.getline(data, 100);
        n++;

        if (n != line_no)
            ofs << data;
        else {
            while(tt < count2) {
                while(data[ii] != 124) {
                    arr[ii] = data[ii];
                    ii++;
                }

                arr[ii] = '|';
                ii++;

                tt++;
            }

            int j = 0, k = ii;

            while(newValue[j] != '\0') {
                arr[k] = newValue[j];
                k++;
                j++;
            }
            arr[k] = '|';
            k++;

            while(data[ii] != 124) {
                ii++;
            }
            ii++;

            while (data[ii] != '\0') {
                arr[k] = data[ii];
                k++;
                ii++;
            }

            arr[k] = '\0';

            for(int n = 0 ; arr[n] != '\0' ; n++) {
                cout << arr[n] << " | ";
            }

            ofs << arr;
        }
        ofs << '\n' ;
    }

    ofs.close();
    is.close();

    is.open("temp.txt", ios::in);
    ofs.open(tableName + ".txt", ios::out);

    while (is.get(c))
    {
        ofs << c;
    }
    ofs.close();
    is.close();

    cout << "\n Record Successfully Updated..! " << endl ;
}

void delete_record(string q)
{
    string  tableName, colName, value, t = "";
    int i=1;
    ofstream outfile;
    ifstream infile;
    char data[100];
    string temp2;
    temp2="temp";


    while(q[i] != 32) {
       t += q[i];
       i++;
    }
    i++;

    //cout << "\n t = " << t << endl;

    if(t == "*") {
        while(q[i] != 32) {
           i++;
        }
        i++;

        while(q[i] != ';') {
           tableName += q[i];
           i++;
        }
        i++;


        if(checktable(tableName))
        {
            infile.open(tableName + ".txt",ios::in);
            outfile.open(temp2 + ".txt",ios::out);

            infile.getline(data,100);
            outfile<<data;

            outfile.close();
            infile.close();
            infile.open(temp2 + ".txt",ios::in);
            outfile.open(tableName + ".txt",ios::out);
            infile.getline(data,100);
            outfile<<data;
        }
        else
        {
            cout<<"\n Table does not exists..! "<<endl;
        }
    }
    else {
        while(q[i] != 32) {
           tableName += q[i];
           i++;
        }
        i++;

        

        if(checktable(tableName))
        {
            while(q[i] != 32) {

               i++;
            }
            i++;

            while(q[i] != 61) {

              colName += q[i];
              i++;
            }
            i += 2;

            while(q[i] != 34) {

              value += q[i];
              i++;
            }
            i++;

    
        }
        else
        {
            cout<<"\n Table does not exists..! "<<endl;
        }

        ifstream is;
        int line_no = 1, count = 0, ii = 0, flag = 0;
        char data[100];
        string temp;

        memset(data, 0, sizeof(data));

        is.open(tableName + ".txt", ios::in);
        is.getline(data, 100);

    

        while(data[ii] != '\0') {
            temp = "" ;

            while(data[ii] != 124) {
                temp += data[ii];
    
                ii++;
            }
            ii++;
            count++;

        
            if(temp == colName) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            cout << "\n Column name specified doesn't exist..! " << endl ;
        }


        while(!is.eof()) {

            memset(data, 0, sizeof(data));
            is.getline(data,100);


            temp = "";
            line_no++;
            ii = 0;

            for(int k = 0 ; k < count ; k++) {
                temp = "" ;
                while(data[ii] != 124) {
                    temp += data[ii];
                    ii++;
                }
                ii++;

            }
            if(temp == value) {
                break;
            }
        }



        is.clear();
        is.seekg(0);
        ofstream ofs;
        ofs.open("temp.txt", ios::out);

        char c;
        int n = 1;

        while (is.get(c))
        {
            if (c == '\n')
                n++;

            if (n != line_no)
                ofs << c;
        }

        ofs.close();
        is.close();
        is.open("temp.txt", ios::in);
        ofs.open(tableName + ".txt", ios::out);

        while (is.get(c))
        {
            ofs << c;
        }
        ofs.close();
        is.close();
    }

    cout << "\n Record Successfully Deleted..! " << endl ;
}