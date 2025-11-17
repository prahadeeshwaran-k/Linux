Process A waiting...
Process A GOT the resource!

Process B waiting...
Process B GOT the resource!

Process C waiting...
Process C GOT the resource!

Process D waiting... (semval=0)
(waiting...)

After 5 seconds:
Process A RELEASED → semval becomes 1
Process D GOT the resource!
