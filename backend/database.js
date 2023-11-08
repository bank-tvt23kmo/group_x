const mysql = require('mysql2');
const dotenv=require('dotenv');
dotenv.config();

const connection=mysql.createPool(process.env.SQL_SERVER);
/*
const connection = mysql.createPool({
  host: 'localhost',
  user: 'peppiuser',
  password: 'peppipass',
  database: 'peppi'
});*/
module.exports = connection;