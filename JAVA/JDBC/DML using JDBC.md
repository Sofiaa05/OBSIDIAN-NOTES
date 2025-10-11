```java
        try{
            Connection con = DriverManager.getConnection(url, user, password);
            Statement stmt = con.createStatement();
        //inserting data
            stmt.executeUpdate("insert into doctors value(10, 'kanu verma', 'cardiology', 'dwarka sector-12')");

		//deleting data
            stmt.executeUpdate("delete from doctors where id>9");

		//updating data
            stmt.executeUpdate("update doctors set specialty='Dermatology' where name='kanu verma'");

            //closing resources (or just use try with resources for automatic closing connection and releasing resources)
            stmt.close();
            con.close();
        }catch (Exception e){

```

---
## DML using JDBC PreparedStatement
```java

```

![[Pasted image 20250721211136.png]]