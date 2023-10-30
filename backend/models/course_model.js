const db = require('../database');

const course = {
  getAll: function(callback) {
    return db.query('select * from course', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from course where idcourse=?', [id], callback);
  },
  add: function(course, callback) {
    return db.query(
      'insert into course (coursename,greditpoints) values(?,?)',
      [course.coursename, course.greditpoints],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from course where idcourse=?', [id], callback);
  },
  update: function(id, course, callback) {
    return db.query(
      'update course set coursename=?,greditpoints=? where idcourse=?',
      [course.coursename, course.greditpoints, id],
      callback
    );
  }
};
module.exports = course;