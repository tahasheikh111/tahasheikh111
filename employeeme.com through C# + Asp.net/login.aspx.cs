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
    
    public partial class login1 : System.Web.UI.Page
    {
        //make connection string for connection
        string strcon = ConfigurationManager.ConnectionStrings["con"].ConnectionString;

        protected void Page_Load(object sender, EventArgs e)
        {
            //profileButton.Visible = false;
            if (Session["Username"] != null)
            {
                profileButton.Text = Session["Username"].ToString();
            }
        }
        protected void Button1_click(object sender, EventArgs e)
        {
            //Session["ButtonVisible"] = true;
            string username; // Replace this with the actual username retrieved from the login form
            

            //in built class of sql connection
            try
            {
                SqlConnection con = new SqlConnection(strcon);
                // to check whetaher the connection is create con is object of connection
                if (con.State == ConnectionState.Closed)
                {
                    con.Open();
                }
                //fire sql query whwn connection is open
                SqlCommand cmd = new SqlCommand("select * from seller where email='"+loginTextbox1.Text.Trim() +"' AND password='"+loginTextbox2.Text.Trim()+ "'", con);
                SqlCommand cmdforuser= new SqlCommand("select * from [dbo].[User] where email='" + loginTextbox1.Text.Trim() + "' AND password='" + loginTextbox2.Text.Trim() + "'", con);
                // connection with data base and reading what this query gives us result
                //connected architecture
                SqlDataReader dr=cmd.ExecuteReader();
                
                if (dr.HasRows)
                {
                    while (dr.Read())
                    {
                        // 3 vallue is position of email block in sql server
                        Response.Write("<script> alert('" + dr.GetValue(3).ToString() + "'); </script>");
                        username = dr.GetValue(3).ToString();
                        Session["Username"] = username;
                        break; // if more then more data is placed at same
                    }
                   
                    //if (Session["ButtonVisible"] != null && (bool)Session["ButtonVisible"] == true)
                    //{
                    //    profileButton.Visible = true;
                    //}
                    //else
                    //{
                    //    profileButton.Visible = false;
                    //}

                }
                else
                {
                    dr.Close();
                    SqlDataReader dr1 = cmdforuser.ExecuteReader();
                    if (dr1.HasRows)
                    {
                        while (dr1.Read())
                        {
                            // 3 vallue is position of email block in sql server
                            Response.Write("<script> alert('" + dr1.GetValue(3).ToString() + "'); </script>");
                            username = dr1.GetValue(3).ToString();
                            Session["Username"] = username;
                            break; // if more then more data is placed at same
                        }

                    }
                    else
                    {
                        Response.Write("<script> alert('Invalid creedentials'); </script>");
                    }
                    
                    
                }
               
            }
            catch (Exception ex)
            {
                Response.Write("<script> alert('" + ex.Message + "'); </script>");
            }
            if (Session["Username"] != null)
            {
                profileButton.Text = Session["Username"].ToString();
            }

        }
        protected void profileButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("profilepage.aspx");
        }
        protected void signupButton1_click(object sender, EventArgs e)
        {
            Response.Redirect("usersignup.aspx");
        }
    }
}