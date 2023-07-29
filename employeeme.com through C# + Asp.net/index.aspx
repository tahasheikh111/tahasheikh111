<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="dbproject.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <link href="bootstrap/css/bootstrap.min.css" rel="stylesheet" />
    <link href="datatables/css/jquery.dataTables.min.css" rel="stylesheet" />
    <link href="fontawesome/css/all.css" rel="stylesheet" />


    <script src="bootstrap/js/jquery-3.4.1.slim.min.js"></script>
    <script src="bootstrap/js/popper.min.js"></script>
    <script src="bootstrap/js/bootstrap.min.js"></script>

    <script src="datatables/js/jquery.dataTables.min.js"></script>
    <style>
         body {
        font-family: 'Ubuntu', sans-serif;
        color: white;
        margin: 0px;
        padding: 0px;
        background: url("imgs/Importance-of-employee-training.png");
        background-color: rgb(200, 120, 189);
        background-repeat: no-repeat;
        background-attachment: fixed;
        background-size: cover; /*to responsive*/
    }

    .left {
        position: absolute;
        left: 34px;
        top: 20px;
        display: inline-block;
    }

    .left img {
       
        width: 60px;
       
        padding-left: 30px;
    }

    .left div {
        text-align: center;
        font-family: 'Wallpoet', cursive;
    }

    .mid {
        display: block;
        width: 39%;
        margin: 15px auto;
    }
    .myclassbtn{
        margin: 45px 9px;
    }
    .right {
        position: absolute;
        right: 34px;
        top: 20px;
        display: inline-block;
    }

    .navbar {
       
        display: inline-block;
      
    }

    .navbar li {
        display: inline-block;
        font-size: 3vh;
        padding-right: 3vh;
    }

    .navbar li a {
        color: white;
        text-decoration: none;
        line-height: 40px;
        gap: 5vh;

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
        font-family: 'Splash', cursive;
        border: 0px solid white;
        margin: 50px 10px;
        padding: 20px;
        width: 15%;
        border-radius: 14px;
        text-align: center;
    }
    
   

    @media screen and (min-height: 876px) {
        .container {
            width: 90%;
            margin: 50px auto;
            padding: 10px;
        }
        .mid{
            display: block;
            width: max-content;
            margin: 120px 50px;
        }
        .container h1{
            font-size: 5vh;
        }
        .btn {
            margin: 15px 9px;
            color: white;
            background-color: rgba(0, 0, 0, 0.896);
            padding: 4px 14px;
            border: 2px solid white;
            border-radius: 10px;
            font-size: xx-large;
            cursor: pointer;
        }
        .my-input{
            width:100px;
            height:54px;
        }
        .logophoto{
            font-size: 5em;
        }

    }
       
  

    .conatiner h1 {
        
        text-align: center;
    }

    .form-group input {
        display: block;
        text-align: center;
        width: 12em;
        margin: 10px auto;
    }
    #logo{
        font-size:3vh;
    }

    </style>
   
</head>
<body>
    
   
   
    <div class="Header" >
        <div class="left">
            <i class="fas fa-briefcase fa-lg logophoto" style="display:inline-block "></i>
           <%-- <img src="img/baggg.png" alt="">--%>
            <div id="logo" style="display:inline-block">EMPLOYEE  ME </div>
        </div>
        <div class="mid">
            <ul class="navbar">
                <li><a href="index.aspx" class="active">HOME</a></li>
               
                <li><a href="seller.aspx">BECOME SELLER</a></li>

                <li><a href="findservice.aspx">FIND SERVICE</a></li>
                
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
        <h1>FIND THE PERFECT SERVICE FOR YOUR BUISNESS</h1>
        
            <div class="form-group">
              <form method="post" action="search.aspx">

              
                       <input type="text" name="searchTerm" placeholder="Search..." class="my-input" />
                       <button class="btn" type="submit" onclick="redirectButton_Click">Search</button>
              </form>
           
    
    </div>

     
   
</body>
</html>
