<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="profilepage.aspx.cs" Inherits="dbproject.profilepage" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
   <title>EMPLOYEE ME </title>
</head>
    <link
    href="https://fonts.googleapis.com/css2?family=Anek+Latin:wght@200&family=Exo+2:wght@900&family=Ubuntu:wght@300&display=swap"
    href="https://fonts.googleapis.com/css2?family=Anek+Latin:wght@200&family=Exo+2:wght@900&family=Ubuntu:wght@300&family=Wallpoet&display=swap"
    rel="stylesheet">
<link rel="stylesheet" href="css/style.css">
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>

<style>
       body {
        background-color: solid white;
        font-family: 'Ubuntu', sans-serif;
        color: #8a2be2;
        margin: 0px;
        padding: 0px;
        
        background-repeat: no-repeat;
        background-attachment: fixed;
        background-size: 100% 100%;
    }

    .left {
        background-color:blueviolet;
        position: absolute;
        left: 34px;
        top: 10px;
        display: inline-block;
    }

    .left img {
        width: 60px;
        background-color:blueviolet;
        padding-left: 30px;
    }

    .left div {
        text-align: center;
        font-family: 'Wallpoet', cursive;
    }

    .mid {
       background-color: blueviolet;
        display: block;
        padding-left: 346px;
        padding-bottom: 15px;
       
    }

    .right {
        position: absolute;
        right: 34px;
        top: 20px;
        display: inline-block;
    }

     .navbar {

        background-color:blueviolet;
        padding-top: 15px;
        padding-left:20px;
        display: inline-flex;
    }

    .navbar li {
        display: inline-block;
        font-size: 18px;
        padding-right: 40px;
    }

    .navbar li a {
        color: white;
        text-decoration: none;
        line-height: 40px;
        gap: 40px;

    }

    .navbar li a:hover,
    .navbar li a.active {
        color: gray;
    }

    .btn {
        margin: 15px 9px;
        color: white;
        background-color: rgba(0, 0, 0, 0.896);
        padding: 4px 14px;
        border: 2px solid white;
        border-radius: 10px;
        font-size: 15px;
        cursor: pointer;
    }
    .myclassbtn{
        margin: 45px 9px;
    }

    .btn:hover {
        background-color: gray;
        text-decoration: underline;
    }

    .container {
        color: blueviolet;
        font-family: 'Splash', cursive;
        border: 2px solid blueviolet;
        margin: 60px 200px;
        padding: 20px;
        text-align: center;
        border-radius: 14px;
        inline-size:max-content;
    }

    .conatiner h1 {
        
        text-align: inherit;
    }

    .form-group input {
        display: block;
        text-align: center;
        width: 140px;
        margin-left: auto;
        margin-right: auto;
        margin-bottom: 10px;
    }

  

footer {
    
    border: 2px solid rgb(117, 111, 122);
    position: fixed;
    bottom: 0;
}

@media (max-height:800px) {
    footer {
        position: static;
    }
    header {
        padding-top: 40px;
    }
}

.footer-distributed {
    background-color:blueviolet;
    box-sizing: border-box;
    width: 100%;
    text-align: left;
    font: bold 16px sans-serif;
    padding: 15px 8px 0px 8px;
    margin-top: 140px;
}

.footer-distributed .footer-left, .footer-distributed .footer-center, .footer-distributed .footer-right {
    display: inline-block;
    vertical-align: top;
}

/* Footer left */

.footer-distributed .footer-left {
    width: 30%;
}

.footer-distributed h3 {
    color: solid white;
    font: normal 36px 'Cookie', cursive;
    margin: 0;
}


.footer-distributed h3 span {
    color: solid white ;
}

/* Footer links */

.footer-distributed .footer-company-name {
    color: #000000;
    font-size: 14px;
    font-weight: normal;
    margin: 1opx;
}

/* Footer Center */

.footer-distributed .footer-center {
    width: 35%;
}

.footer-distributed .footer-center i {
    background-color: #33383b;
    color: #ffffff;
    font-size: 25px;
    width: 38px;
    height: 38px;
    border-radius: 50%;
    text-align: center;
    line-height: 42px;
    margin: 10px 15px;
    vertical-align: middle;
}

.footer-distributed .footer-center i.fa-envelope {
    font-size: 17px;
    line-height: 38px;
}

.footer-distributed .footer-center p {
    display: inline-block;
    color: solid white;
    vertical-align: middle;
    margin: 0;
}

.footer-distributed .footer-center p span {
    display: block;
    font-weight: normal;
    font-size: 14px;
    line-height: 2;
}

.footer-distributed .footer-center p a {
    color: solid white;
    text-decoration: none;
    ;
}

/* Footer Right */

.footer-distributed .footer-right {
    color: solid white;
    width: 30%;
}

.footer-distributed .footer-company-about {
    line-height: 20px;
    color: #92999f;
    font-size: 13px;
    font-weight: normal;
    margin: 0;
}

.footer-distributed .footer-company-about span {
    display: block;
    color: #ffffff;
    font-size: 18px;
    font-weight: bold;
    margin-bottom: 20px;
}

.footer-distributed .footer-icons {
    margin-top: 25px;
}

.footer-distributed .footer-icons a {
    display: inline-block;
    width: 35px;
    height: 35px;
    cursor: pointer;
   
    border-radius: 2px;
    font-size: 20px;
  
    text-align: center;
    line-height: 35px;
    margin-right: 3px;
    margin-bottom: 5px;
}

.footer-distributed .footer-icons a:hover {
    background-color: #3F71EA;
}

.footer-links a:hover {
    color: grey;
}
.header {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 20%;
  background-color: #8a2be2;
}

.content {
  margin-top: 20%;
  /* add other styles for the content */
}
.photo{
    height: 15%;
    width:100%;
    color: white;
    margin: 0px;
    padding: 0px;
    background: url("imgs/Importance-of-employee-training.png");
    background-color: rgb(200, 120, 189);
    background-repeat: no-repeat;
    background-attachment: fixed;
    background-size: cover; /*to responsive*/
}
@media (max-width: 880px) {
    .footer-distributed .footer-left, .footer-distributed .footer-center, .footer-distributed .footer-right {
        display: block;
        width: 100%;
        margin-bottom: 40px;
        text-align: center;
    }
    .footer-distributed .footer-center i {
        margin-left: 0;
    }
}   
</style>


<body>
    <form runat="server">
        
   
        
        <div class="conatiner">
            <div class="photo"></div>
       
        <h1><b>Name </b>: <i><asp:Label ID="resultLabel" CssClass="fa-buy-n-large" runat="server" Text=""></asp:Label></i>
        <hr /> </h1>
        
        <h1><b>Email </b>: <i><asp:Label ID="Label1" runat="server" CssClass="fa-buy-n-large" Text=""></asp:Label></i>
        <hr /> </h1>
        
        <h1><b>Password </b>: <i><asp:Label ID="Label2" runat="server" Text=""></asp:Label></h1></i>
        
         </div>
   
        <div class="container">
  <h2>My History</h2>
  <hr>
  <h3> HIRED PERSON DETAILS</h3>
  <div class="table-responsive">
    <table class="table table-striped">
      
      <tbody>
        <asp:GridView ID="historyResults" runat="server" AutoGenerateColumns="False">
          <Columns>
            <asp:BoundField DataField="firstname" HeaderText="First Name" />
            <asp:BoundField DataField="lastname" HeaderText="Last Name" />
            <asp:BoundField DataField="dob" HeaderText="Date of Birth" DataFormatString="{0:MM/dd/yyyy}" />
            <asp:BoundField DataField="gender" HeaderText="Gender" />
            <asp:BoundField DataField="services" HeaderText="Services" />
            <asp:BoundField DataField="sellerID" HeaderText="Seller ID" />
          </Columns>
        </asp:GridView>
      </tbody>
    </table>
  </div>
</div>






    
   </form>
</body>

</html>
