package com.company;

import java.sql. * ;

class Main{
    public static void main(String args[]) {
        try {
            String dbUrl = "jdbc:mysql://localhost:3306/our_db";
            String username = "root";
            String password = "";
            Class.forName("com.mysql.jdbc.Driver");
            Connection myconnection = DriverManager.getConnection(dbUrl, username, password);
            Statement mystatement = myconnection.createStatement();
            ResultSet myresultset = mystatement.executeQuery("select * from EMPLOYEES");
            System.out.println("Connected");
            while (myresultset.next()) {
                System.out.println("Employee ID : " + myresultset.getString("ID"));
                System.out.println("Employee Age : " + myresultset.getString("AGE"));
                System.out.println("Employee Name : " + myresultset.getString("FIRST_NAME") + " " + myresultset.getString("LAST_NAME"));
            }

        } catch(Exception e) {
            System.out.println(e);
        }
    }
}