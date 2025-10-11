#### Compile code 
```bash
javac -cp .:mysql-connector.jar Test.java
```

#### Run
```bash
javac -cp .:mysql-connector.jar Test
```

```java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Test {
    public static void main(String[] args) {
        // Database credentials and connection URL
        String url = "jdbc:mysql://localhost:3306/hearthealthy"; 
        String user = "root"; //username
        String password = "sofia@123"; // Put your MySQL password here

        try {
            // Create connection
            Connection con = DriverManager.getConnection(url, user, password);
            System.out.println("Connected to MySQL database!");

            // Create statement
            Statement stmt = con.createStatement();

            // Sample query (Make sure table `users` exists)
            ResultSet rs = stmt.executeQuery("SELECT * FROM doctors");

            // Iterate through the results
            while (rs.next()) { //next() returns true: if there is next data present, else false.
                System.out.println("ID: " + rs.getInt("id") +
                                   ", Name: " + rs.getString("name") +
                                   ", specialty: " + rs.getString("specialty"));
            }

            // Close connection
            con.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
```

#### PreparedStatement


##### Example finding doctors by asking id from user
```java
import java.sql.*;
import java.util.Scanner;
public class PrepareStmt {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/hearthealthy"; // Replace `testdb` with your DB name
        String user = "root"; // Change if your MySQL username is different
        String password = "sofia@123"; // Put your MySQL password here

        try{
            Connection con = DriverManager.getConnection(url, user, password);
            PreparedStatement stmt = con.prepareStatement("select * from doctors where id=?");
            
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter id of the doctor: ");
            int id = sc.nextInt();

            stmt.setInt(1, id);
            ResultSet rs = stmt.executeQuery();

            while(rs.next()){
                System.out.print("Id: " + rs.getInt("id") + " ");
                System.out.print("Name: " + rs.getString("name") + " ");
                System.out.print("Specialty: " + rs.getString("specialty") + " ");
            }

        }catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}
```

-