const db = require('../database');

const studentgrade={
    getByUsername:function(username, callback){
        return db.query('select coursename, grade from student inner join grade on student.idstudent=grade.idstudent inner join course on course.idcourse=grade.idcourse where username=?',[username],callback);
    }
}

module.exports=studentgrade;
