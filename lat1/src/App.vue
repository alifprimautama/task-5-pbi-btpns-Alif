<template>
  <input type="text" v-model="name" />
  <h4>Name: {{ name }}</h4>
</template>

<script>
export default{
  name: "App",
  data(){
    return{
      name: "",
    };
  },
};
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
