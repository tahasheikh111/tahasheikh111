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
    public partial class setpackages : System.Web.UI.Page
    {
        string strcon = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
        int maxid = 0;
        protected void Page_Load(object sender, EventArgs e)
        {
            

        }
        protected void ok_Click(object sender, EventArgs e)
        {
            setup();

        }
      
        
        void setup()
        {
            string connectionString = ConfigurationManager.ConnectionStrings["con"].ConnectionString;
            SqlConnection connection = new SqlConnection(connectionString);
            connection.Open();

            // Perform the search and return a DataTable of search results
            string query = "SELECT max(sellerID) from seller";
            SqlCommand command = new SqlCommand(query, connection);
            maxid = Convert.ToInt32(command.ExecuteScalar());
            Response.Write("<script> alert('" + maxid + "'); </script>");
            // Clean up
            connection.Close();
            connection.Open();
            SqlCommand cmd = new SqlCommand("INSERT INTO pakagesinfo (gold,golddescription,silver,silverdescription,diamond,diamonddescription,sellerID) values (@gold,@golddescription,@silver,@silverdescription,@diamond,@diamonddescription,@sellerID)", connection);

            float goldPriceValue;
            if (!float.TryParse(goldprice.Text, out goldPriceValue))
            {
                // Handle the case where goldprice.Text is null or not a valid float
                // You can set a default value or display an error message
                goldPriceValue = 0; // Set a default value
                                    // You can display an error message like this:
                                    // Response.Write("<script> alert('Please enter a valid Gold Price'); </script>");
            }

            cmd.Parameters.AddWithValue("@gold", goldPriceValue);
            cmd.Parameters.AddWithValue("@golddescription", golddescription.Text.Trim());

            float silverPriceValue;
            if (!float.TryParse(silverprice.Text, out silverPriceValue))
            {
                // Handle the case where silverprice.Text is null or not a valid float
                // You can set a default value or display an error message
                silverPriceValue = 0; // Set a default value
                                      // You can display an error message like this:
                                      // Response.Write("<script> alert('Please enter a valid Silver Price'); </script>");
            }

            cmd.Parameters.AddWithValue("@silver", silverPriceValue);
            cmd.Parameters.AddWithValue("@silverdescription", silverdescription.Text.Trim());

            float diamondPriceValue;
            if (!float.TryParse(diamondprice.Text, out diamondPriceValue))
            {
                // Handle the case where diamondprice.Text is null or not a valid float
                // You can set a default value or display an error message
                diamondPriceValue = 0; // Set a default value
                                       // You can display an error message like this:
                                       // Response.Write("<script> alert('Please enter a valid Diamond Price'); </script>");
            }

            cmd.Parameters.AddWithValue("@diamond", diamondPriceValue);
            cmd.Parameters.AddWithValue("@diamonddescription", diamonddescription.Text.Trim());
            cmd.Parameters.AddWithValue("@sellerID", maxid);
            //float goldPriceValue = float.Parse(goldprice.Text);
            //cmd.Parameters.AddWithValue("@gold", goldPriceValue);
            //cmd.Parameters.AddWithValue("@golddescription", golddescription.Text.Trim());
            //float silverPriceValue = float.Parse(silverprice.Text);
            //cmd.Parameters.AddWithValue("@silver",silverPriceValue);
            //cmd.Parameters.AddWithValue("@silverdescription", silverdescription.Text.Trim());
            //float diamondPriceValue = float.Parse(diamondprice.Text);
            //cmd.Parameters.AddWithValue("@diamond", diamondPriceValue);
            //cmd.Parameters.AddWithValue("@diamonddescription", diamonddescription.Text.Trim());
            //cmd.Parameters.AddWithValue("@sellerID", maxid);
            cmd.ExecuteNonQuery(); // fire the query
            connection.Close();
            Response.Write("<script> alert('Successful ADDDED IN PACAKAGES INFO TABLE'); </script>");


        }
      
    }
}