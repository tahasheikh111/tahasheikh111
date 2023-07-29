<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="search.aspx.cs" Inherits="dbproject.search" %>

<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>availableresults</title>
    <style>
        body {
            background-color: solid white;
            font-family: 'Ubuntu', sans-serif;
            color: white;
            margin: 0;
            padding: 0;
            background-repeat: no-repeat;
            background-attachment: fixed;
            background-size: 100% 100%;
            background: url("imgs/Importance-of-employee-training.png");
            background-size: contain; /*to responsive*/
        }
        .myclassbtn{
            margin: 45px 9px;
        }
        .left {
           
            position: absolute;
            font-family: 'Ubuntu', sans-serif;
            left: 34px;
            top: 20px;
            display: inline-block;
        }

            .left i {
                width: 60px;
                background-color: blueviolet;
                padding-left: 30px;
            }

            .left div {
                text-align: center;
                font-family: 'Wallpoet', cursive;
                position: relative;
                top:-16px;
            }

        .mid {
           
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
           
            padding-top: 15px;
            padding-left: 20px;
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
            inline-size: max-content;
        }

        .conatiner h1 {
            text-align: center;
        }

        .form-group input {
            display: block;
            text-align: center;
            margin: 10px auto;
        }



        footer {
           
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
            background-color: #722b90;
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
                    color: solid white;
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



        .container2 {
            color: blueviolet;
            font-family: 'Splash', cursive;
            /*            border: 1px solid blueviolet*/;
            max-width: 800px;
            margin: 0 auto;
            text-align: center;
        }

        .search-result-card {
            display: inline-block;
            width: 300px;
            height: 400px;
            margin: 10px;
            transition: all 0.3s ease-in-out;
            background-color: azure;
            border-radius: 6px;
        }

        .Header {
            padding: 0;
            margin: 0;
        }
        /*
        .search-result-card {
            flex-direction: column;
            justify-content: center;
            align-items: center;
            border: 1px solid #ddd;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            padding: 16px;
            margin-bottom: 16px;
           
        }
*/
        .search-result-card:hover {
            transform: translateY(-4px);
            box-shadow: 0 8px 16px rgba(0, 0, 0, 0.2);
        }

        .card-image {
            width: 100%;
            height: 200px;
            object-fit: cover;
            border-radius: 8px;
        }

        .card-title {
            font-size: 24px;
            font-weight: lighter;
            margin-bottom: 8px;
            color: black;
        }

        .card-description {
            font-size: 16px;
            margin-bottom: 8px;
        }

        .card-row {
            display: flex;
            flex-direction: row;
            flex-wrap: wrap;
            justify-content: space-between;
        }

        .card-price {
            font-size: 20px;
            font-weight: lighter;
            color: black;
        }
        .gridview-noborder table, .gridview-noborder th, .gridview-noborder td {
            border: none !important;
        }
        .container2 table, .container2 th, .container2 td {
            border: none !important;
        }
        #form1{
            border: none !important;
        }
        table {
            border-collapse: collapse !important;
            border: none !important;
        }
    </style>
</head>

<body>

    <div class="Header">
        <div class="left">

            <img src="imgs/icons8-bag-50.png" alt="">
            <div style="display: inline-block">EMPLOYEE  ME </div>
        </div>
        <div class="mid">
            <ul class="navbar">
                <li><a href="index.aspx" class="active">HOME</a></li>

                <li><a href="seller.aspx">BECOME SELLER</a></li>

                <li><a href="findservice.aspx">FIND SERVICE</a></li>

                <li><a href="login.aspx">LOGIN</a></li>
            </ul>
        </div>
        <form id="form1" runat="server">
            <asp:GridView ID="searchResults" class="container2" runat="server" AutoGenerateColumns="False">
                <Columns>
                    <asp:TemplateField>
                        <ItemTemplate>
                            <div class="card-row">
                                <div class="search-result-card">
                                    <div class="card-content">
                                        <h1>NAME</h1>
                                        <h2 class="card-title"><%# Eval("firstname") %>  <%# Eval("lastname") %> </h2>

                                        <%--<h2 class="card-title"><%# Eval("firstname") %>  </h2>
                                    <p class="card-description"><%# Eval("lastname") %></p>--%>

                                        <h1>CONTACT INFO</h1>
                                        <p class="card-price"><%# Eval("email") %></p>
                                        <h1>SERVICES</h1>
                                        <p class="card-price"><%# Eval("services") %></p>
                                        <asp:Button ID="hireButton" CssClass="btn" runat="server" Text="Hire!" CommandArgument='<%# Eval("email") %>' OnClick="redirectButton_Click" />
                                        <%--<button class="btn" type="submit" onclick="redirectButton_Click('<%# Eval("email") %>')">Hire!</button>--%>
                                    </div>

                                    <%--<img src="<%# Eval("ImageUrl") %>" alt="<%# Eval("Name") %>" class="card-image" />--%>
                                </div>
                            </div>
                        </ItemTemplate>
                    </asp:TemplateField>
                </Columns>
            </asp:GridView>
            <%--<div class="container2">
            <div class="table-responsive">
              <asp:GridView ID="searchResults" CssClass="table table-striped table-bordered table-hover" runat="server" AutoGenerateColumns="true">
                <HeaderStyle CssClass="bg-blueviolet text-light" />
                <RowStyle CssClass="text-center" />
                <AlternatingRowStyle CssClass="table-active" />
                <PagerStyle CssClass="pagination justify-content-center" />
            </asp:GridView>
            </div>
        </div>--%>
        </form>

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
