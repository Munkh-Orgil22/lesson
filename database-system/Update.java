import java.sql.*;

public class DataBase {
		
	public static void main(String[] args) throws SQLException {
//		static final String jdbc_driver = "" ;
		String DB_URL = "jdbc:mysql://localhost:3306/our_db" ;
		String USER = "root" ;
		String PASS = "" ;
		
        int employeeNumber = 1002;
		String lastName = "Dorj" ;
		String firstName = "Bat" ; 
		String email = "test@gmail.com";
		
		try {
			Connection connection = DriverManager.getConnection(DB_URL, USER, PASS) ;
			String sql = "UPDATE employees SET lastName=?, firstName=?, email=? WHERE employeeNumber = ?" ;
			PreparedStatement statement = connection.prepareStatement(sql) ;
            System.out.println(sql);
			
			statement.setString(1,  lastName);
			statement.setString(2, 	firstName);
			statement.setString(3,  email);
            statement.setInt(4,  employeeNumber);
			
			int rows = statement.executeUpdate() ;
			if (rows > 0){
				System.out.println("Amjilttai update hiigdlee");
			}
		}
		catch (SQLException ex){
			ex.printStackTrace(); 
		}
	}

}