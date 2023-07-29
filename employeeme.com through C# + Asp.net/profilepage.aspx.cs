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
    public partial class profilepage : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["Username"] != null)
            {
                
                // Connect to database
                string connectionString1 = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
                using (SqlConnection connection1 = new SqlConnection(connectionString1))
                {
                    connection1.Open();
                    SqlCommand command1 = new SqlCommand("SELECT firstname, lastname,dob, email,gender,password,userID FROM [dbo].[User] WHERE email = @username", connection1);
                    command1.Parameters.AddWithValue("@username", Session["Username"].ToString());
                    SqlCommand command2 = new SqlCommand("SELECT firstname, lastname,dob, email,gender,services,password,sellerID FROM [dbo].[seller] WHERE email = @username", connection1);
                    command2.Parameters.AddWithValue("@username", Session["Username"].ToString());
                    SqlDataReader reader = command1.ExecuteReader();
                   
                    if (reader.Read())
                    {
                        // Store data in variables
                        string firstName = reader["firstname"].ToString();
                        string lastName = reader["lastname"].ToString();
                        string email = reader["email"].ToString();
                        string password = reader["password"].ToString();

                        // Print data on screen
                        resultLabel.Text = firstName + " " + lastName;
                        Label1.Text = email;
                        Label2.Text = password ;


                    }
                    else
                    {
                        reader.Close();
                        SqlDataReader reader1 = command2.ExecuteReader();
                        if (reader1.Read())
                        {
                            // Store data in variables
                            string firstName = reader1["firstname"].ToString();
                            string lastName = reader1["lastname"].ToString();
                            string email = reader1["email"].ToString();
                            string password = reader1["password"].ToString();

                            // Print data on screen
                            resultLabel.Text = firstName + " " + lastName;
                            Label1.Text = email;
                            Label2.Text = password;


                        }
                        else
                        {
                            Response.Write("<h1>No data found.</h1>");
                        }
                        reader1.Close();

                    }
                    
                }
                

                if (!IsPostBack)
                {
                    // Retrieve data from database
                    string connectionString = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
                    using (SqlConnection connection = new SqlConnection(connectionString))
                    {
                        connection.Open();
                        SqlCommand command = new SqlCommand("SELECT firstname, lastname, dob, gender, services, password, sellerID FROM [dbo].[HISTORY] WHERE username = @username", connection);
                        command.Parameters.AddWithValue("@username", Session["Username"].ToString());
                        SqlDataAdapter adapter = new SqlDataAdapter(command);
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);
                        historyResults.DataSource = dt;
                        historyResults.DataBind();
                    }
                }
            }
        }
       

    }
}