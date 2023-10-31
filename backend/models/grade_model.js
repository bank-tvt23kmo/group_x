const db = require('../database');

const grade = {
  getAll: function(callback) {
    return db.query('select grade,DATE_FORMAT(grade_date,"%d.%m.%Y") as "grade_date",idstudent,idcourse from grade', callback);
  },
  getById: function(id, callback) {
    return db.query('select grade,DATE_FORMAT(grade_date,"%d.%m.%Y") as "grade_date",idstudent,idcourse from grade where idgrade=?', [id], callback);
  },
  add: function(grade, callback) {
    return db.query(
      'insert into grade (grade,grade_date,idstudent,idcourse) values(?,?,?,?)',
      [grade.grade, grade.grade_date, grade.idstudent, grade.idcourse],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from grade where idgrade=?', [id], callback);
  },
  update: function(id, grade, callback) {
    return db.query(
      'update grade set grade=?, grade_date=?, idstudent=?, idcourse=? where idgrade=?',
      [grade.grade, grade.grade_date, grade.idstudent, grade.idcourse, id],
      callback
    );
  }
};
module.exports = grade;