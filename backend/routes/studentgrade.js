const express = require('express');
const router = express.Router();
const studentgrade = require('../models/studentgrade_model');

router.get('/:username',
    function (request, response) {
        studentgrade.getByUsername(request.params.username, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        })
    });


module.exports = router;
