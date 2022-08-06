import java.sql.*;

public class Delete {
		
	public static void main(String[] args) throws SQLException {
//		static final String jdbc_driver = "" ;
		String DB_URL = "jdbc:mysql://localhost:3306/our_db" ;
		String USER = "root" ;
		String PASS = "" ;
		
		String email = "test@gmail.com" ;
		
		try {
			Connection connection = DriverManager.getConnection(DB_URL, USER, PASS);
			
			String sql = "DELETE FROM employees WHERE email = ?" ;
			
			PreparedStatement statement = connection.prepareStatement(sql) ;
			
			statement.setString(1, email);
			
			int rows = statement.executeUpdate() ;
			if (rows > 0){
				System.out.println("Amjilttai delete hiigdlee");
			}
		}
		catch (SQLException ex){
			ex.printStackTrace(); 
		}
	}

}