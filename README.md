#Database_management_system_using-CPP#

##STEPS TO RUN THE PROJECT :-##

######STEP 1:-> Simply execute the code.######

######Step 2:->AFTER EXECUTING THE CODE, USE THE FOLLOWING INPUTS TO FORM THE DATABASE######


    (i)To create table : ->
              /*
              CREATE TABLE STUDENTS ( GRNO INT , NAME VARCHAR , PHONE INT , BRANCH VARCHAR )

              CREATE TABLE EMPLOYEES ( ID INT , NAME VARCHAR , MOBILE INT , DEPT VARCHAR )
    (ii)To insert data into table : ->   

              INSERT INTO STUDENTS VALUES ( 11910234 , Navneet , 8493023174 , CS )

              INSERT INTO STUDENTS VALUES ( 11910113 , Krishna , 6006277089 , IT )

              INSERT INTO STUDENTS VALUES ( 11910900 , Samruddhi , 6455853174 , CS )

              INSERT INTO STUDENTS VALUES ( 11910233 , Akanksha , 8493968251 , Mech )

              INSERT INTO STUDENTS VALUES ( 11910354 , Swaminath , 9865124786 , CS )

              INSERT INTO EMPLOYEES VALUES ( 1 , NAVNEET , 8493023174 , HR )
              
    (iii)To check error handling of datatype mismatch table : ->

              ****datatype error****

              INSERT INTO STUDENTS VALUES ( 11910354 , Swaminath , CS , 9865124786 )
    
    (iv)To check error handling of column mismatch table : ->
              ****column error****

              INSERT INTO STUDENTS VALUES ( 11910354 , Swaminath , CS )

    (v)To select the data from the table : ->
    
              SELECT * FROM STUDENTS

              SELECT NAME , PHONE FROM STUDENTS

              SELECT NAME FROM STUDENTS WHERE GRNO = 11910234
              
     (vi)To get description of table : ->

              DESCRIBE STUDENTS

     (vii)To update the data in table : ->
     
              UPDATE STUDENTS SET NAME = KARTIK WHERE GRNO = 11910234 

     (viii)To delete data from the table : ->
     
              DELETE FROM STUDENTS WHERE GRNO = 11910234
              
     (ix)To drop the table from schema : ->

              DROP TABLE STUDENTS

              */
