import java.sql.*;

public class Select {
		
	public static void main(String[] args) throws SQLException {
//		static final String jdbc_driver = "" ;
		String DB_URL = "jdbc:mysql://localhost:3306/our_db" ;
		String USER = "root" ;
		String PASS = "" ;
		int numColumn = 23;
		
		try {
			Connection connection = DriverManager.getConnection(DB_URL, USER, PASS) ;	
			
			Statement statement = connection.createStatement() ;
			
			String sql = "select c.*, p.*, o.* from customers AS c, payments AS p, orders AS o where p.customerNumber = c.customerNumber AND c.customerNumber = 112 AND o.customerNumber = c.customerNumber";

			ResultSet result = statement.executeQuery(sql) ;
		
			while (result.next()) {
				String ResultData = "";
				for (int i = 1; i <= numColumn; i++) {
					if (i != numColumn)
						ResultData += result.getString(i) + ", ";
					else
						ResultData += result.getString(i);
				}
				
				System.out.println(ResultData);
			}
		}
		catch (SQLException ex){
			ex.printStackTrace(); 
		}
	}

}