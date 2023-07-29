using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


namespace dbproject
{
    
    public partial class WebForm1 : System.Web.UI.Page
    {
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
        protected void profileButton_Click(object sender, EventArgs e)
        {
            Response.Redirect("profilepage.aspx");
        }
        
    }
}