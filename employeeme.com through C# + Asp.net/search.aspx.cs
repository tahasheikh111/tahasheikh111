using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace dbproject
{
    public partial class search : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
           
            string searchTerm = Request.Form["searchTerm"];
            if (!string.IsNullOrEmpty(searchTerm))
            {
                // Perform the search and display the results
                DataTable results = PerformSearch(searchTerm);
                DisplayResults(results);
            }
        }

        private DataTable PerformSearch(string searchTerm)
        {
            // Connect to the SQL database
           // Response.Write("<script> alert('in search'); </script>");
            string connectionString = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
            SqlConnection connection = new SqlConnection(connectionString);
            connection.Open();

            // Perform the search and return a DataTable of search results
            string query = "SELECT firstname,lastname,dob,email,gender,services,password FROM seller WHERE services LIKE '%' + @SearchTerm + '%'";
            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@SearchTerm", searchTerm);
            SqlDataAdapter adapter = new SqlDataAdapter(command);
            DataTable results = new DataTable();
            adapter.Fill(results);

            // Clean up
            connection.Close();

            return results;
        }

        private void DisplayResults(DataTable results)
        {
            // Display the search results on the web page using a GridView control
            searchResults.DataSource = results;
            searchResults.DataBind();
        }
        //protected void redirectButton_Click(object sender, EventArgs e)
        //{
        //    Response.Write("<script> alert('redirect button function'); </script>");
        //    // Get the email from the command argument of the button that was clicked
        //    Button hireButton = (Button)sender;
        //    string email = hireButton.CommandArgument;
        //    Response.Write("<script> alert('" + email + "'); </script>");
        //    // Use the email to retrieve the data from the database
        //    string connectionString = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
        //    SqlConnection connection = new SqlConnection(connectionString);
        //    connection.Open();
        //    string query = "SELECT firstname,lastname,dob,email,gender,services,password,sellerID FROM seller WHERE email = @email";
        //    SqlCommand command = new SqlCommand(query, connection);
        //    command.Parameters.AddWithValue("@email", email);
        //    SqlDataReader reader = command.ExecuteReader();

        //    // Store the data in the database
        //    // Define the command outside the if block
        //    SqlCommand command1 = null;

        //    if (reader.Read())
        //    {
        //        // Get the data from the reader
        //        string firstname = reader["firstname"].ToString();
        //        string lastname = reader["lastname"].ToString();
        //        string dob = reader["dob"].ToString();
        //        string gender = reader["gender"].ToString();
        //        string services = reader["services"].ToString();
        //        string password = reader["password"].ToString();
        //        string sellerID = reader["sellerID"].ToString();

        //        // Store the data in the database using another SQL query
        //        // ...
        //        string username = (string)Session["Username"];
        //        Response.Write("<script> alert('" + username + "'); </script>");

        //        // Do something with the username

        //        string insertCommand = "INSERT INTO HISTORY (firstname, lastname, dob, gender, services, password,sellerID,username) VALUES (@FirstName, @LastName, @DOB, @Gender, @Services, @Password,@sellerID,@username)";
        //        command1 = new SqlCommand(insertCommand, connection);
        //        command1.Parameters.AddWithValue("@FirstName", firstname);
        //        command1.Parameters.AddWithValue("@LastName", lastname);
        //        command1.Parameters.AddWithValue("@DOB", dob);
        //        command1.Parameters.AddWithValue("@Gender", gender);
        //        command1.Parameters.AddWithValue("@Services", services);
        //        command1.Parameters.AddWithValue("@Password", password);
        //        command1.Parameters.AddWithValue("@sellerID", sellerID);
        //        command1.Parameters.AddWithValue("@username", username);

        //        // Execute the command
        //        int rowsAffected = command1.ExecuteNonQuery();
        //    }

        //    // Close the connection and the reader
        //    connection.Close();
        //    reader.Close();

        //}
        protected void redirectButton_Click(object sender, EventArgs e)
        {
            //Response.Write("<script> alert('redirect button function'); </script>");
            // Get the email from the command argument of the button that was clicked
            Button hireButton = (Button)sender;
            string email = hireButton.CommandArgument;
            //Response.Write("<script> alert('" + email + "'); </script>");
            // Use the email to retrieve the data from the database
            string connectionString = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
            SqlConnection connection = new SqlConnection(connectionString);
            connection.Open();
            string query = "SELECT firstname,lastname,dob,email,gender,services,password,sellerID FROM seller WHERE email = @email";
            SqlCommand command = new SqlCommand(query, connection);
            command.Parameters.AddWithValue("@email", email);
            SqlDataReader reader = command.ExecuteReader();

            // Store the data in the database
            if (reader.Read())
            {
                // Get the data from the reader
                string firstname = reader["firstname"].ToString();
                string lastname = reader["lastname"].ToString();
                string dob = reader["dob"].ToString();
                string gender = reader["gender"].ToString();
                string services = reader["services"].ToString();
                string password = reader["password"].ToString();
                string sellerID = reader["sellerID"].ToString();

                // Store the data in the database using another SQL query
                // ...
                string username = (string)Session["Username"];
                //Response.Write("<script> alert('" + username + "'); </script>");
                if (username.Length > 50)
                {
                    username = username.Substring(0, 50);
                }
                // Do something with the username
                if (username==null)
                {
                    username = "unknown";
                }

                string insertCommand = "INSERT INTO HISTORY (firstname, lastname, dob, gender, services, password,sellerID,username) VALUES (@FirstName, @LastName, @DOB, @Gender, @Services, @Password,@sellerID,@username)";
                SqlCommand command1 = new SqlCommand(insertCommand, connection);
                command1.Parameters.AddWithValue("@FirstName", firstname);
                command1.Parameters.AddWithValue("@LastName", lastname);
                command1.Parameters.AddWithValue("@DOB", dob);
                command1.Parameters.AddWithValue("@Gender", gender);
                command1.Parameters.AddWithValue("@Services", services);
                command1.Parameters.AddWithValue("@Password", password);
                command1.Parameters.AddWithValue("@sellerID", sellerID);
                command1.Parameters.AddWithValue("@username", username);

                reader.Close(); // close the reader before executing the command
                int rowsAffected = command1.ExecuteNonQuery();
            }
            else
            {
                reader.Close(); // close the reader if no data is found
            }
            connection.Close();
        }

    }
}