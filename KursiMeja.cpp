<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Three.js 3D Chair with Table and Book</title>
    <style>
        body { margin: 0; }
        canvas { display: block; }
    </style>
</head>
<body>
    <script type="module">
        import * as THREE from 'https://cdn.jsdelivr.net/npm/three@0.147.0/build/three.module.js';

        let scene, camera, renderer;

        function init() {
            // Scene
            scene = new THREE.Scene();

            // Camera
            camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
            camera.position.set(0, 5, 10);

            // Renderer
            renderer = new THREE.WebGLRenderer({ antialias: true });
            renderer.setSize(window.innerWidth, window.innerHeight);
            document.body.appendChild(renderer.domElement);

            // Ground
            const groundGeometry = new THREE.PlaneGeometry(20, 20);
            const groundMaterial = new THREE.MeshStandardMaterial({ color: 0xFFFDD0 }); // Cream color
            const ground = new THREE.Mesh(groundGeometry, groundMaterial);
            ground.rotation.x = -Math.PI / 2;
            ground.position.y = 0;
            scene.add(ground);

            // Chair components
            const chairMaterial = new THREE.MeshStandardMaterial({ color: 0x8B4513 });

            // Seat
            const seatGeometry = new THREE.BoxGeometry(2, 0.2, 2);
            const seat = new THREE.Mesh(seatGeometry, chairMaterial);
            seat.position.set(0, 2, -3);
            scene.add(seat);

            // Backrest
            const backrestGeometry = new THREE.BoxGeometry(2, 2, 0.2);
            const backrest = new THREE.Mesh(backrestGeometry, chairMaterial);
            backrest.position.set(0, 3, -3.9);
            scene.add(backrest);

            // Legs
            const legGeometry = new THREE.BoxGeometry(0.2, 2, 0.2);

            const leg1 = new THREE.Mesh(legGeometry, chairMaterial);
            leg1.position.set(-0.9, 1, -3.9);
            scene.add(leg1);

            const leg2 = new THREE.Mesh(legGeometry, chairMaterial);
            leg2.position.set(0.9, 1, -3.9);
            scene.add(leg2);

            const leg3 = new THREE.Mesh(legGeometry, chairMaterial);
            leg3.position.set(-0.9, 1, -2.1);
            scene.add(leg3);

            const leg4 = new THREE.Mesh(legGeometry, chairMaterial);
            leg4.position.set(0.9, 1, -2.1);
            scene.add(leg4);

            // Table components
            const tableMaterial = new THREE.MeshStandardMaterial({ color: 0x8B4513 });

            // Tabletop
            const tabletopGeometry = new THREE.BoxGeometry(3, 0.2, 3);
            const tabletop = new THREE.Mesh(tabletopGeometry, tableMaterial);
            tabletop.position.set(0, 2.5, 0);
            scene.add(tabletop);

            // Table legs
            const tableLegGeometry = new THREE.BoxGeometry(0.2, 2.3, 0.2);

            const tableLeg1 = new THREE.Mesh(tableLegGeometry, tableMaterial);
            tableLeg1.position.set(-1.2, 1.15, -1.2); // Closer to the center
            scene.add(tableLeg1);

            const tableLeg2 = new THREE.Mesh(tableLegGeometry, tableMaterial);
            tableLeg2.position.set(1.2, 1.15, -1.2); // Closer to the center
            scene.add(tableLeg2);

            const tableLeg3 = new THREE.Mesh(tableLegGeometry, tableMaterial);
            tableLeg3.position.set(-1.2, 1.15, 1.2); // Closer to the center
            scene.add(tableLeg3);

            const tableLeg4 = new THREE.Mesh(tableLegGeometry, tableMaterial);
            tableLeg4.position.set(1.2, 1.15, 1.2); // Closer to the center
            scene.add(tableLeg4);

            // Book
            const bookGeometry = new THREE.BoxGeometry(1, 0.2, 1.5);
            const bookMaterial = new THREE.MeshStandardMaterial({ color: 0x0000FF }); // Blue color
            const book = new THREE.Mesh(bookGeometry, bookMaterial);
            book.position.set(0, 2.6, 0);
            scene.add(book);

            // Light
            const light = new THREE.DirectionalLight(0xffffff, 1);
            light.position.set(5, 10, 7.5);
            scene.add(light);

            const ambientLight = new THREE.AmbientLight(0x404040); // Soft white light
            scene.add(ambientLight);

            // Render the scene
            animate();
        }

        function animate() {
            requestAnimationFrame(animate);
            renderer.render(scene, camera);
        }

        window.addEventListener('resize', () => {
            renderer.setSize(window.innerWidth, window.innerHeight);
            camera.aspect = window.innerWidth / window.innerHeight;
            camera.updateProjectionMatrix();
        });

        init();
    </script>
</body>
</html>
