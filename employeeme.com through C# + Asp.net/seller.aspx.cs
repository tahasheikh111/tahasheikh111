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
    public partial class login : System.Web.UI.Page
    {
        //make connection string for connection
        string strcon = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
        

        protected void Page_Load(object sender, EventArgs e)
        {
            //if (Session["ButtonVisible"] != null && (bool)Session["ButtonVisible"] == true)
            //{
            //    profileButton.Visible = true;
            //}
            //else
            //{
            //    profileButton.Visible = false;
            //}
            if (Session["Username"] != null)
            {
                profileButton.Text = Session["Username"].ToString();
            }
        }
     

        //sign up click event
        protected void Button1_click(object sender, EventArgs e)
        {
            setupseller();
            Response.Redirect("setpackages.aspx"); // set up pacakges
        }
        void setupseller()
        {
            try
            {
                //in built class of sql connection
                SqlConnection con = new SqlConnection(strcon);
                // to check whetaher the connection is create con is object of connection
                if (con.State == ConnectionState.Closed)
                {
                    con.Open();
                }
                //fire sql query whwn connection is open
                SqlCommand cmd = new SqlCommand("INSERT INTO seller (firstname,lastname,dob,email,gender,services,password) values (@firstname,@lastname,@dob,@email,@gender,@services,@password)", con);
                cmd.Parameters.AddWithValue("@firstname", Textbox1.Text.Trim());
                cmd.Parameters.AddWithValue("@lastname", Textbox2.Text.Trim());
                cmd.Parameters.AddWithValue("@dob", dobTextBox.Text.Trim());
                cmd.Parameters.AddWithValue("@email", Textbox3.Text.Trim());

                string gender = "";

                if (maleoption.Checked)
                {
                    gender = "Male";
                }
                else if (femaleoption.Checked)
                {
                    gender = "Female";
                }
                else if (otheroption.Checked)
                {
                    gender = "Other";
                }
                Response.Write("<script> alert(gender); </script>");
                cmd.Parameters.AddWithValue("@gender", gender);
                cmd.Parameters.AddWithValue("@services", optionsDropDownList.SelectedItem.Value);
                cmd.Parameters.AddWithValue("@password", Textbox5.Text.Trim());
                //fire the sql query
                cmd.ExecuteNonQuery();
                con.Close();
                Response.Write("<script> alert('Successful Become a seller'); </script>");
            }
            catch (Exception ex)
            {
                Response.Write("<script> alert('" + ex.Message + "'); </script>");
            }
            //Response.Write("<script> alert('Successful'); </script>");
        }
        protected void profileButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("profilepage.aspx");
        }
    }
}