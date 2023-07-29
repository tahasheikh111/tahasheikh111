<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="findservice.aspx.cs" Inherits="dbproject.becomeaseller" %>

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
        color: white;
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
        top: 20px;
        display: inline-block;
    }

    .left i {
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

    .btn:hover {
        background-color: gray;
        text-decoration: underline;
    }

    .container {
        color: blueviolet;
        font-family: 'Splash', cursive;
        border: 2px solid blueviolet;
        margin: 60px 400px;
        padding: 20px;
        text-align: center;
        border-radius: 14px;
        inline-size:fit-content;
    }

    .conatiner h1 {
        
        text-align: center;
    }

    .form-group input {
        display: block;
        text-align: center;
        margin: 10px auto;
    }

  .myclassbtn{
        margin: 45px 9px;
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
    margin: 10px;
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
/*
form checkbox*/
.custom-checkbox input[type=checkbox] {
  display: none;
}

.custom-checkbox label {
  display: inline-block;
  position: relative;
  padding-left: 28px;
  margin-bottom: 10px;
  cursor: pointer;
  font-size: 16px;
  color: #666;
}

.custom-checkbox label:before {
  content: "";
  display: inline-block;
  position: absolute;
  left: 0;
  top: 0;
  width: 18px;
  height: 18px;
  border: 1px solid #bbb;
  border-radius: 3px;
}

.custom-checkbox input[type=checkbox]:checked + label:before {
  content: "\2713";
  color: #fff;
  background-color: blueviolet;
  border-color: #3a3;
}

</style>
<body>
    
      <div class="Header">
        <div class="left">
           <%--<i class="fas fa-briefcase fa-lg"></i>--%>
            <img src="imgs/icons8-bag-50.png" alt="">
            <div>EMPLOYEE  ME </div>
        </div>
        <div class="mid">
            <ul class="navbar">
                <li><a href="index.aspx">HOME </a></li>
                <li><a href="seller.aspx"class="active" > BECOME SELLER </a></li>
                <li><a href="findservice.aspx">FIND SERVICE </a></li>
                <li><a href="login.aspx">LOGIN</a></li>
            </ul>
        </div>
         <form runat="server">
      <div class="right">
          <asp:Button ID="profileButton" runat="server" Text="Profile" CssClass="btn btn-primary btn-lg myclassbtn" OnClick="profileButton_Click" />
      </div>
           </form>

      </div>
         <div class="container">
        <h1>DISCOVER THE IDEAL SERVICE TAILORED TO YOUR BUSINESS NEEDS</h1>
        
            <div class="form-group">
              <form method="post" action="search.aspx">

              
                       <input type="text" name="searchTerm" placeholder="Search..." class="my-input" />
                       <button class="btn" type="submit" onclick="redirectButton_Click">Search</button>
              </form>
           
            </div>
    </div>

    <footer class="footer-distributed">

        <div class="footer-left">
            <h3>EMPLOYEE ME</h3>

            <p class="footer-company-name">Copyright © 2023  All rights reserved</p>
        </div>

        <div class="footer-center">
            <p class="footer-company-about">
                <span>About the company</span>
                <strong>Tuition Khana</strong> is a group of 4 students Fazeel , Taha , Mousa and BUtt they all participated 
                and created this website
            </p>
           
        </div>
        <div class="footer-right">
            <i class="fa-brands fa-square-facebook"></i>


        </div>
    </footer>


</body>
</html>
