let serial; // serial object
let APIdata; // holds the entire API response
let pop; // holds the precipitation probability information

// preload is called before anything else (even setup()!)
// useful for calling APIs and loading images/video/sounds
function preload() {
  let url = 'https://api.weatherbit.io/v2.0/forecast/daily?lat=39.9075&lon=116.39723&city_id=1816670&city=Beijing&postal_code=100102&country=CN&station=22&days=1&key=c1e5882e171f4a58a87234c596ba9ea2';
  APIdata = loadJSON(url);
}

function setup() {
  createCanvas(400, 400);
  console.log('*****API response below****');
  console.log(APIdata);
  console.log('*****API response above****');
  // parse the API for what we're looking for and print it out
  pop = APIdata.data[0].pop; // get precipitation probability information
  console.log('Precipitation probability:' + pop);

  // initialize serial port
  serial = new p5.SerialPort();
  let options = {baudrate: 9600};
  serial.on('list', gotList);
  serial.on('connected', serverConnected);
  serial.open('/dev/tty.usbmodem14601', options); // open the port
}

function gotList(portList) {
  console.log('Available serial ports:');
  for (let i = 0; i < portList.length; i++) {
    console.log(i + ' ' + portList[i]);
  }
}

function serverConnected() {
  console.log('Connected to the serial server');
}

function draw() {
  background(220);
  fill(0);
  textSize(18);
  textAlign(CENTER);
  text('Beijing Precipitation Probability: ' + pop + '%', width / 2, height / 2);
    console.log('*****API response below****');
  console.log(APIdata);
  console.log('*****API response above****');
  // parse the API for what we're looking for and print it out
  pop = APIdata.data[0].pop; // get precipitation probability information
  console.log('Precipitation probability:' + pop);
  
 ///pop = '9' ; // test to check if rain animation works
  
if (pop == '0') {
  serial.write("A");
  console.log("writing");
}
  else {
    serial.write("R");
  console.log("writing");
  }
  setTimeout(draw, 1000);
}
