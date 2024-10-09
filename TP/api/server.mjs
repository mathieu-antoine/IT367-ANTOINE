import Fastify from "fastify";

export function createServer() {
  const fastify = Fastify();

  fastify.get("/feature/:code", function(req,res){
    const code =req.params.code;
    res.send({"code": code, "enabled": true});
  });

  return fastify;
}
