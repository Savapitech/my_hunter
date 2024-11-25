/*
 * My_hunter
 * Repository : my_hunter
 * File : server.js
*/

const express = require('express')
const app = express()
const logger = require('@savalet/easy-logs')
const fs = require('fs')

function log(req, res, route_name) {
    let IP
    if (req.headers['x-forwarded-for'] == undefined)
        IP = req.socket.remoteAddress.replace("::ffff:", "")
    else
        IP = req.headers['x-forwarded-for'].split(',')[0]
    res.on('finish', () => {
        return logger.debug(`${req.method} ${route_name} [FINISHED] [FROM ${IP}] [CODE ${res.statusCode}]`)
    })
}

logger.info("The API is starting...")

app.get('/', function (req, res) {
    res.send('Hunter api is running')
    log(req, res, "/")
})

app.get('/score', function (req, res) {
    res.send(fs.readFileSync('./score.txt', 'utf8'))
    log(req, res, "/score")
})

app.post('/score', function (req, res) {
    if (req.query.score.length > 10)
        return res.send("The gived score is to high !")
    if (req.query.score.length < 3)
        return res.send("The score is required and need to be higher than 99 !")
    fs.writeFileSync('./score.txt', req.query.score)
    res.send("OK, Score changed to: " + req.query.score);
    log(req, res, "/score")
})

app.listen(3000)
logger.info(`The API is listening on port 3000`)
